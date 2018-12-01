#pragma once
//#include"nodes.h"

#include <complex>
#include <string>
class inductance //:public nodes , public impedance
{
	//private:


public:
	std::string name;
	float value;
	//float phase;
	int firstNode;
	int secondNode;
	std::complex<double>z;
	//float omega;
	//inductance();



	inductance(std::string n, float v, int n1, int n2);
	//void split(int n);
	//void setMagnitude(float);
	//void setPhase(float);
	//float getMagnitude();
	//float getPhase();
	void convertToImpedance(float w);
	~inductance();
};
