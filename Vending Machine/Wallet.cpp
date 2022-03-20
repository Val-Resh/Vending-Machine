#include "Wallet.h"
#include <iostream>

Wallet::Wallet()
{
	this->wallet = {};
}

Wallet::~Wallet()
{
	for (auto& coin : this->wallet)
	{
		delete coin;
	}
	this->wallet.clear();
}

void Wallet::putCoin(InterfaceCoin* coin)
{
	this->wallet.push_back(coin);
}

InterfaceCoin* Wallet::retrieveCoin(double value)
{
	for (unsigned i = 0; i < this->wallet.size(); i++)
	{	
		InterfaceCoin *coin = this->wallet[i];
		if (coin->getValue() == value)
		{
			this->wallet.erase(this->wallet.begin()+i);
			return coin;
		}
	}
	return new InterfaceCoin();
}

void Wallet::displayWallet()
{	
	std::cout << "You have the following coins: \n";
	for (InterfaceCoin* coin : this->wallet)
	{	
		std::cout << coin->getValue() << ", ";
	}
	std::cout << std::endl;
}


