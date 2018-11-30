//#pragma once
//#include "inductance.h"
#include <complex>
class resistance
{
public:
	float value;
	int firstNode;
	int secondNode;
	std::complex <double> z;
	//nt z;
	resistance( float v,int n1,int n2 );
	
	void convertToImpedance();

	//resistance();
	~resistance();
};

