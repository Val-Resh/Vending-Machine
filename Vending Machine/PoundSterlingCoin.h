#pragma once
#include "InterfaceCoin.h"

/*
* Represents a coin from the sterling pound category.
*/
class PoundSterlingCoin: public InterfaceCoin
{
public:
	PoundSterlingCoin(double value);
};