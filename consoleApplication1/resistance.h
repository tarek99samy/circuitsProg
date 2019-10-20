#pragma once
#include <complex>
#include <string>
class resistance
{
public:
	std::string name;
	float R;
	int firstNode;
	int secondNode;
	std::complex <double> z;
	
	resistance();
	resistance(std::string n, float v,int n1,int n2 );
	void convertToImpedance();
	void setResistance(float r);
	float getResistance();
	~resistance();
};

