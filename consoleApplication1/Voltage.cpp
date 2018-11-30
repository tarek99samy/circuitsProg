#include "Voltage.h"


Voltage::Voltage(float v,  int n1,int n2 , float ph)
{
	value = v;
	firstNode = n1;
	secondNode = n2 ;
	phase =ph;
}


Voltage::~Voltage(void)
{
}
