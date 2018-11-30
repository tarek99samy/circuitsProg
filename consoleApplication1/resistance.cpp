#include "resistance.h"



resistance::resistance(float v,int n1,int n2)

{

	value = v;
	firstNode = n1;
	secondNode = n2;
}

void resistance::convertToImpedance(){

	z.real( value);
	z.imag( 0);
}




resistance::~resistance()
{
}
