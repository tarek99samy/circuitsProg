#pragma once
//#include "inductance.h"
#include <complex>
#include <string>
class resistance
{
public:
	std::string name;
	float value;
	int firstNode;
	int secondNode;
	std::complex <double> z;
	//nt z;
	resistance(std::string n, float v,int n1,int n2 );
	
	void convertToImpedance();

	//resistance();
	~resistance();
};

