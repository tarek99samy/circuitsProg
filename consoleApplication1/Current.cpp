#include "Current.h"

Current::Current(string n, float v, int n1, int n2, float ph)
{
	name = n, value = v, firstNode = n1, secondNode = n2, phase = ph;
}

Current::~Current(void)
{
}
