#pragma once
#include "InterfaceCoin.h"
#include <map>
#include <vector>
#include <string>

class VendingMachine
{
public:
	VendingMachine(std::map<std::string, int> *productsWithCount, std::vector<InterfaceCoin*> *initialCoins) { this->productsWithCount = productsWithCount; this->coinsInMachine = initialCoins; };
	~VendingMachine();
	void displayProducts();

private:
	std::map<std::string, int>* productsWithCount;
	std::vector<InterfaceCoin*>* coinsInMachine;
};


