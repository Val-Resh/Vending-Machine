#pragma once
#include "InterfaceCoin.h"
#include "ProductFactory.h"
#include "Wallet.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

class VendingMachine
{
public:
	VendingMachine(std::map<std::string, int>* productsWithCount, std::vector<InterfaceCoin*>* initialCoins)
	{
		this->productsWithCount = productsWithCount;
		this->coinsInMachine = initialCoins;
		this->productFactory = new ProductFactory();
	};
	~VendingMachine();
	void insertCoin(InterfaceCoin* coin);
	void displayProducts();
	void displayCoinsInHolder();
	void purchaseProduct(Wallet* wallet, std::string product);

private:
	ProductFactory *productFactory;
	std::map<std::string, int>* productsWithCount;
	std::vector<InterfaceCoin*>* coinsInMachine;
	std::vector<InterfaceCoin*> coinsInHolder;
	double calculateCoinsInHolder();
	void placeCoinsFromHolderToMachine();
	std::vector<InterfaceCoin*> getChange(double value);
};


