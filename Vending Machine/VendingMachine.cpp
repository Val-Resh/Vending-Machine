#include "VendingMachine.h"

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
	delete productsWithCount;
	for (auto& coin : *coinsInMachine)
	{
		delete coin;
	}
	delete coinsInMachine;
	for (auto& coin : coinsInHolder)
	{
		delete coin;
	}
	coinsInHolder.clear();
	delete this->productFactory;
}

void VendingMachine::insertCoin(InterfaceCoin* coin)
{
	this->coinsInHolder.push_back(coin);
}

void VendingMachine::displayCoinsInHolder()
{
	std::cout << "Inserted Coins Total: " << calculateCoinsInHolder() << std::endl;
}

double VendingMachine::calculateCoinsInHolder()
{	
	double sum = 0.00;
	for (auto& coin : coinsInHolder)
	{	
		sum += coin->getValue();
	}
	return sum;
}

void VendingMachine::purchaseProduct(Wallet* wallet, std::string product)
{
	double totalCoinsInHolder = calculateCoinsInHolder();
	for (auto const& pairs : *productsWithCount)
	{
		if (pairs.first.compare(product))
		{
			if (pairs.second > 0)
			{
				ProductInterface* prod = this->productFactory->getProductInstance(product);
				double productPrice = prod->getPrice();
				if (productPrice < totalCoinsInHolder)
				{
					std::cout << "You have purchased a " << prod->getProductName() << std::endl;
					double change = productPrice - totalCoinsInHolder;
					placeCoinsFromHolderToMachine();
					std::vector<InterfaceCoin*> changeCoins = getChange(change);
					for (auto& coin : changeCoins)
					{
						wallet->putCoin(coin);
					}
					std::cout << change << " returned as change." << std::endl;
				}
				else
				{
					std::cout << "Not enough credit. Insert more coins." << std::endl;
				}
				delete prod;
			}
			else
			{
				std::cout << "Product not in stock." << std::endl;
			}
			break;
		}
	}
}

void VendingMachine::placeCoinsFromHolderToMachine()
{
	for (int i = 0; i < coinsInHolder.size(); i++)
	{
		coinsInMachine->push_back(coinsInHolder.at(i));
	}
	coinsInHolder.clear();
}

std::vector<InterfaceCoin*> VendingMachine::getChange(double value)
{
	std::vector<InterfaceCoin*> change;
	std::vector<int> indecesToErase;
	std::sort(coinsInMachine->begin(), coinsInMachine->end());
	for (int i = coinsInMachine->size() - 1; i >= 0; i--)
	{
		double coin = coinsInMachine->at(i)->getValue();
		while (value >= coin)
		{
			value -= coin;
			change.push_back(coinsInMachine->at(i));
		}
	}
	for (int index : indecesToErase)
	{
		coinsInMachine->erase(coinsInMachine->begin() + index);
	}
	return change;
}