#include "VendingMachine.h"
#include <iostream>

void VendingMachine::displayProducts()
{
	for (auto const& pairs : *productsWithCount)
	{
		std::cout << pairs.first
			<< ": " << pairs.second << " in stock." << std::endl;
	}
}

VendingMachine::~VendingMachine()
{
	productsWithCount->clear();
	for (auto& coin : *coinsInMachine)
	{
		delete coin;
	}
	coinsInMachine->clear();
}