#include "capacitance.h"



capacitance::capacitance(std::string n,double c, int n1, int n2){
	capa = c;
	firstNode = n1;
	secondNode = n2;
	name = n;
}

void capacitance::convertToImpedance(double w){ //-j/wc
	z.real ( 0);
	z.imag ( (-1) / (50*capa));
}

capacitance::~capacitance()
{
}
