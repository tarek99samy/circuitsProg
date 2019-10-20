#pragma once
#include<complex>
#include <string>

class capacitance
{
public:
	std::string name;
	double C;
	float omega;
	int firstNode, secondNode;
	std::complex<double>z;


	capacitance();
	capacitance(std::string n,double c, int n1, int n2);
	float getCapacitance();
	void setCapacitance(float c);
	void convertToImpedance(double w);

	~capacitance();
};