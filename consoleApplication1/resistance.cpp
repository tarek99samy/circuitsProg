#include "resistance.h"



resistance::resistance()
{
	R = 0, firstNode = -1, secondNode = -1, name = "";
}

resistance::resistance(std::string n,float v,int n1,int n2)

{
	name = n;
	R = v;
	firstNode = n1;
	secondNode = n2;
}

void resistance::convertToImpedance(){

	z.real( R);
	z.imag( 0);
}

void resistance::setResistance(float r)
{
	R = r;
}

float resistance::getResistance()
{
	return R;
}




resistance::~resistance()
{
}
