#include "Voltage.h"


Voltage::Voltage(std::string n,float v,  int n1,int n2 , float ph)
{
	name = n;
	value = v;
	firstNode = n1;
	secondNode = n2 ;
	phase =ph;
}

void Voltage::setValue(float v)
{
	value = v;
}

float Voltage::getValue()
{
	return value;
}


Voltage::~Voltage(void)
{
}
