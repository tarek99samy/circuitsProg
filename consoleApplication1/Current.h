//#pragma once
#include<complex.h>
class Current
{
public:
	float value;
	float phase;
	int firstNode;
	int secondNode;
	

	Current(float v,  int n1,int n2 , float ph=0);
	
	~Current(void);
};


