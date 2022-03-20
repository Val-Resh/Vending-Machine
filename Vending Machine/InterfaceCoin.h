#pragma once
#include <string>

/*
* An interface class that encapsulates a coin. 
* Different types of coins should implement this class.
*/
class InterfaceCoin
{
private:
	double defaultCoinValue = 0.00;

public:
	InterfaceCoin() { this->value = defaultCoinValue; };
	double getDefaultCoinValue() { return this->defaultCoinValue; };
	double getValue() { return this->value; };

protected:
	double value;
};
