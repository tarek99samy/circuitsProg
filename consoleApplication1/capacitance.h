#pragma once
#include<complex>
#include <string>

class capacitance
{
public:
	std::string name;
	double capa;
	float omega;
	int firstNode, secondNode;
	std::complex<double>z;
	capacitance(std::string n,double c, int n1, int n2);
	void convertToImpedance(double w);

	~capacitance();
};