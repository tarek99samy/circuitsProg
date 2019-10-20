#pragma once
#include<complex.h>
#include <string>
#include"resistance.h"

class Current
{
public:
	float value;
	float phase;
	int firstNode;
	int secondNode;
	string name;

	Current(string n, float v,  int n1,int n2 , float ph=0);
	~Current(void);
};


