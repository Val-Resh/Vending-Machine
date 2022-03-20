#include "PoundSterlingCoin.h"

/*
* Creates a new coin of pound sterling with value passed. If the value is not valid, a default coin is created.
*/
PoundSterlingCoin::PoundSterlingCoin(double value) {
	if (value == 2.00 ||
		value == 1.00 ||
		value == 0.50 ||
		value == 0.20 ||
		value == 0.10 ||
		value == 0.05 ||
		value == 0.01)
	{
		this->value = value;
	}
	else
	{
		this->value = this->getDefaultCoinValue();
	}
}
