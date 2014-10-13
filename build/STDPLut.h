#ifndef __STDP_FUNCTION_LUT_H__
#define __STDP_FUNCTION_LUT_H__

// This is an automatically generated file. 
// STDP Function LUTor v1.0 (C) 2014 Sandor Vasas

namespace STDPLut {
const int 	STDP_LTP_TAO		= 10;//tao_plus of equation; LTP time param
const int 	STDP_LTD_TAO		= 10;//tao_minus of equation; LTD time param
const double STDP_LTP_AMPLITUDE	= 1.000000;//deltaWeight
const double STDP_LTD_AMPLITUDE	= 1.500000;//deltaWeight
const int 	STDP_LTD_LUTSIZE	= 51;//msec
const int 	STDP_LTP_LUTSIZE	= 51;//msec
 
// tao = t_pre - t_post
const float LTD[] = {
		0.00000000f, // tao=0
		-1.35725613f, // tao=1
		-1.22809613f, // tao=2
		-1.11122733f, // tao=3
		-1.00548007f, // tao=4
		-0.90979599f, // tao=5
		-0.82321745f, // tao=6
		-0.74487796f, // tao=7
		-0.67399345f, // tao=8
		-0.60985449f, // tao=9
		-0.55181916f, // tao=10
		-0.49930663f, // tao=11
		-0.45179132f, // tao=12
		-0.40879769f, // tao=13
		-0.36989545f, // tao=14
		-0.33469524f, // tao=15
		-0.30284478f, // tao=16
		-0.27402529f, // tao=17
		-0.24794833f, // tao=18
		-0.22435293f, // tao=19
		-0.20300292f, // tao=20
		-0.18368464f, // tao=21
		-0.16620474f, // tao=22
		-0.15038827f, // tao=23
		-0.13607693f, // tao=24
		-0.12312750f, // tao=25
		-0.11141037f, // tao=26
		-0.10080827f, // tao=27
		-0.09121509f, // tao=28
		-0.08253483f, // tao=29
		-0.07468060f, // tao=30
		-0.06757380f, // tao=31
		-0.06114331f, // tao=32
		-0.05532475f, // tao=33
		-0.05005990f, // tao=34
		-0.04529608f, // tao=35
		-0.04098558f, // tao=36
		-0.03708529f, // tao=37
		-0.03355616f, // tao=38
		-0.03036287f, // tao=39
		-0.02747346f, // tao=40
		-0.02485901f, // tao=41
		-0.02249337f, // tao=42
		-0.02035284f, // tao=43
		-0.01841601f, // tao=44
		-0.01666349f, // tao=45
		-0.01507775f, // tao=46
		-0.01364292f, // tao=47
		-0.01234462f, // tao=48
		-0.01116987f, // tao=49
		-0.01010692f, // tao=50
};
// tao = t_post - t_pre
const float LTP[] = {
		0.00000000f, // tao=0
		0.90483742f, // tao=1
		0.81873075f, // tao=2
		0.74081822f, // tao=3
		0.67032005f, // tao=4
		0.60653066f, // tao=5
		0.54881164f, // tao=6
		0.49658530f, // tao=7
		0.44932896f, // tao=8
		0.40656966f, // tao=9
		0.36787944f, // tao=10
		0.33287108f, // tao=11
		0.30119421f, // tao=12
		0.27253179f, // tao=13
		0.24659696f, // tao=14
		0.22313016f, // tao=15
		0.20189652f, // tao=16
		0.18268352f, // tao=17
		0.16529889f, // tao=18
		0.14956862f, // tao=19
		0.13533528f, // tao=20
		0.12245643f, // tao=21
		0.11080316f, // tao=22
		0.10025884f, // tao=23
		0.09071795f, // tao=24
		0.08208500f, // tao=25
		0.07427358f, // tao=26
		0.06720551f, // tao=27
		0.06081006f, // tao=28
		0.05502322f, // tao=29
		0.04978707f, // tao=30
		0.04504920f, // tao=31
		0.04076220f, // tao=32
		0.03688317f, // tao=33
		0.03337327f, // tao=34
		0.03019738f, // tao=35
		0.02732372f, // tao=36
		0.02472353f, // tao=37
		0.02237077f, // tao=38
		0.02024191f, // tao=39
		0.01831564f, // tao=40
		0.01657268f, // tao=41
		0.01499558f, // tao=42
		0.01356856f, // tao=43
		0.01227734f, // tao=44
		0.01110900f, // tao=45
		0.01005184f, // tao=46
		0.00909528f, // tao=47
		0.00822975f, // tao=48
		0.00744658f, // tao=49
		0.00673795f, // tao=50
};
}; // eof namespace STDPLutor
#endif
