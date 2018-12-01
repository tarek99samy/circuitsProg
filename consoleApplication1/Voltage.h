#pragma once
#include <string>
class Voltage
{
public:
	std::string name;
	float value;
	float phase;
	int firstNode;
	int secondNode;

	Voltage(std::string n,float v,  int n1,int n2 , float ph=0);
	~Voltage(void);
};

