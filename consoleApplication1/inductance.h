#pragma once
//#include"nodes.h"

#include <complex>
#include <string>
class inductance //:public nodes , public impedance
{
	//private:


public:
	std::string name;
	float L;
	float phase;
	int firstNode;
	int secondNode;
	std::complex<double>z;
	inductance();



	inductance(std::string n, float v, int n1, int n2);
	void setPhase(float);
	float getMagnitude();
	float getPhase();
	void convertToImpedance(float w);
	~inductance();
};
