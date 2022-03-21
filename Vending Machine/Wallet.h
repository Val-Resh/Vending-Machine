#pragma once
#include <vector>
#include "PoundSterlingCoin.h"

/*
* Represents the wallet of the user.
* The user can put or retrieve coins from their wallet.
*/
class Wallet
{
public:
	Wallet(std::vector<InterfaceCoin*>* wallet) { this->wallet = wallet; };
	~Wallet();
	void putCoin(InterfaceCoin& coin);
	InterfaceCoin* retrieveCoin(double value);
	void displayWallet();

private:
	std::vector<InterfaceCoin*> *wallet;
};

