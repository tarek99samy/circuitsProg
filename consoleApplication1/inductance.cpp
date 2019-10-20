#include "inductance.h"

inductance::inductance()
{
	L = 0, firstNode = -1, secondNode = -1, phase = -1, name = "";
}

inductance::inductance(std::string n, float v, int n1, int n2)
{
	name = n, firstNode = n1, secondNode = n2, L = v;
}

void inductance::setPhase(float x)
{
	phase = x;
}

float inductance::getMagnitude()
{
	return sqrtf(powf(z.real, 2) + powf(z.imag, 2));
}

float inductance::getPhase()
{
	return phase;
}

void inductance::convertToImpedance(float w)
{
	z.real(0);
	z.imag(w*L);
}

inductance::~inductance()
{
}
