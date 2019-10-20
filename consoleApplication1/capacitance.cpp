#include "capacitance.h"



capacitance::capacitance(std::string n,double c, int n1, int n2){
	C = c;
	firstNode = n1;
	secondNode = n2;
	name = n;
}

float capacitance::getCapacitance()
{
	return C;
}

void capacitance::setCapacitance(float c)
{
	C = c;
}

capacitance::capacitance()
{
	C = 0, firstNode = -1, secondNode = -1, omega = -1, name = "";
}

void capacitance::convertToImpedance(double w){ //-j/wc
	z.real ( 0);
	z.imag ( (-1) / (w*C));
}

capacitance::~capacitance()
{
}
