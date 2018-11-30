//#pragma once
class Voltage
{
public:
	float value;
	float phase;
	int firstNode;
	int secondNode;

	Voltage(float v,  int n1,int n2 , float ph=0);
	~Voltage(void);
};

