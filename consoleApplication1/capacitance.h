#pragma once
#include<complex>

class capacitance
{
public:
	double capa;
	float omega;
	int firstNode, secondNode;
	std::complex<double>z;
	capacitance(double c, int n1, int n2);
	void convertToImpedance(double w);

	~capacitance();
};