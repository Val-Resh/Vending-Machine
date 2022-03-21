#include "Wallet.h"
#include <iostream>

Wallet::~Wallet()
{
	for (auto& coin : *wallet)
	{
		delete coin;
	}
	delete wallet;
}

void Wallet::putCoin(InterfaceCoin& coin)
{
	wallet->push_back(&coin);
}

InterfaceCoin* Wallet::retrieveCoin(double value)
{
	for (unsigned i = 0; i < wallet->size(); i++)
	{	
		InterfaceCoin *coin = wallet->at(i);
		if (coin->getValue() == value)
		{
			wallet->erase(wallet->begin()+i);
			return coin;
		}
	}
	return new InterfaceCoin();
}

void Wallet::displayWallet()
{	
	std::cout << "You have the following coins: \n";
	for (InterfaceCoin* coin : *wallet)
	{	
		std::cout << coin->getValue() << ", ";
	}
	std::cout << std::endl << std::endl;
}


