//#pragma once
//#include"nodes.h"

#include <complex>
class inductance //:public nodes , public impedance
{
private:
	
	
public:
	float value;
	//float phase;
	int firstNode;
	int secondNode;
	std::complex<double>z;
	float omega;
	//inductance();
	
	
	
	inductance(float v , int n1 , int n2);
	void split(int n);
	void setMagnitude(float);
	void setPhase(float);
	float getMagnitude();
	float getPhase();
	void convertToImpedance(float w);
	~inductance();
};
