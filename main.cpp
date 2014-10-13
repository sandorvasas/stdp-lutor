#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

namespace STDPFunctionLutor {

// reference: Abbott STDP (2006)
//	Returns deltaW
inline 
double STDP_Abott(int dt,
						double LTPamplitude, double LTDamplitude, 
						int LTPtimeRange, int LTDtimeRange)
{
	double dw;

	if ( dt > 0) {
		dw = LTPamplitude * exp( -dt / (double)LTPtimeRange );
	} else
	if ( dt < 0 ) {
		dw = LTDamplitude * -exp( dt / (double)LTDtimeRange );
	} else
		dw = 0;

	return dw;
}

//----------------------------------
//
//	make_lut()
//		
//
//----------------------------------
void make_lut(const char* filename, int tao_start=-50, int tao_end=50,
			  int ltpX=10, int ltdX=10, double ltpY=1.0f, double ltdY=1.5f) {
  FILE* f = fopen(filename, "w+");
  
  fprintf(f, "#ifndef __STDP_FUNCTION_LUT_H__\n"
		  "#define __STDP_FUNCTION_LUT_H__\n"
		  "\n"
		  "// This is an automatically generated file. \n"
		  "// STDP Function LUTor v1.0 (C) 2014 Sandor Vasas\n"
		  
		  "\n"
		  "namespace STDPLut {\n"
		  "const int 	STDP_LTP_TAO		= %d;//tao_plus of equation; LTP time param\n"
		  "const int 	STDP_LTD_TAO		= %d;//tao_minus of equation; LTD time param\n"
		  "const double STDP_LTP_AMPLITUDE	= %f;//deltaWeight\n"
		  "const double STDP_LTD_AMPLITUDE	= %f;//deltaWeight\n"
		  "const int 	STDP_LTD_LUTSIZE	= %d;//msec\n"
		  "const int 	STDP_LTP_LUTSIZE	= %d;//msec\n"
		  " \n",
		  ltpX, ltdX, ltpY, ltdY, -tao_start+1, tao_end+1);
  double stdp;
  
  fprintf(f,  "// tao = t_pre - t_post\n");
  fprintf(f,  "const float LTD[] = {\n");
  for ( int t = 0; t >= tao_start; --t )
  {
	stdp = STDP_Abott(t, ltpY, ltdY, ltpX, ltdX);
	
	fprintf(f,  "		%9.8ff, // tao=%d\n", stdp, -t );
  }
  fprintf(f, "};\n");
  
  fprintf(f,  "// tao = t_post - t_pre\n");
  fprintf(f, "const float LTP[] = {\n");
  for ( int t = 0; t <= tao_end; ++t )
  {
	stdp = STDP_Abott(t, ltpY, ltdY, ltpX, ltdX);
	
	fprintf(f,  "		%9.8ff, // tao=%d\n", stdp, t );
  }
  fprintf(f, "};\n");
  
  fprintf(f, "}; // eof namespace STDPLutor\n");
  fprintf(f, "#endif\n");
  
  fclose(f);
};

};


using namespace STDPFunctionLutor;

int main(int argc, char **argv) {
  cout << "===========================================================================" << endl;
    std::cout << "Spike-Timing Dependent Plasticity Function Lookup Table Generator v1.0"<<endl<<
				 "Copyright (C) 2014 Sandor Vasas" << endl <<
		"===========================================================================" << endl <<
				 "Default parameters are:" << endl  <<
				 "ltpX = 10ms, ltdX = 10ms, ltpY = 1.0, ltdY = 1.5" << endl << 
				 "t E [ -50, 50 ]" << endl <<
				 "Filename will be STDPLut.h" << endl;
				 
  char c;
  int ltpx, ltdx;
  double ltpy, ltdy;
  int tao_start, tao_end;
  
  tao_start = -50; 
  tao_end = 50;
  ltpx = 10; ltdx = 10;
  ltpy = 1.0f; ltdy = 1.5f;
	
  while ( c != 'x' && c!= 'X' ) {
	cout << "MENU"<<endl;
	cout << "D to set default parameters" << endl;
	cout << "C to configure"<< endl << "G to generate" << endl << "X to quit." << endl;
	cin >> c;
	
	if (c == 'c' || c == 'C' ) {
	  cout << "(Note: tao = t_post - t_pre)" << endl;
	  cout << "LTD_TIME_RANGE="; cin >> ltdx;
	  cout << "LTP_TIME_RANGE="; cin >> ltpx;
	  cout << "LTD_SCALE_Y="; cin >> ltdy;
	  cout << "LTP_SCALE_Y="; cin >> ltpy;
	  cout << "PLOT_FROM_TAO="; cin >> tao_start;
	  cout << "PLOT_TO_TAO="; cin >> tao_end;
	} else
	if ( c == 'g' || c == 'G' ) {
	  make_lut("STDPLut.h", tao_start, tao_end, ltpx, ltdx, ltpy, ltdy);
	  cout << "LUT generated " << endl;
	} else
	if ( c == 'd' || c == 'D' ) {
	  tao_start = -50; tao_end = 50;
	  ltpx = 10; ltdx = 10;
	  ltpy = 1.0f; ltdy = 1.5f;
	  cout << "Parameters set to default" << endl;
	}
  }
  return 0;
}
