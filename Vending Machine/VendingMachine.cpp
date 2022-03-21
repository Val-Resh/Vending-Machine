#include "VendingMachine.h"

void VendingMachine::displayProducts()
{
	for (auto& pairs : *productsWithCount)
	{	
		ProductInterface *p = this->productFactory->getProductInstance(pairs.first);
		std::cout << pairs.first
			<< ": " << pairs.second << " in stock. Price: " <<
			p->getPrice() << std::endl;
		delete p;
	}
}

void VendingMachine::cancel(Wallet* wallet)
{
	for (int i = 0; i < coinsInHolder.size(); i++)
	{
		wallet->putCoin(*coinsInHolder.at(i));
	}
	coinsInHolder.clear();
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
	delete productFactory;
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
	for (auto& pairs : *productsWithCount)
	{
		if (pairs.first == product)
		{
			if (pairs.second > 0)
			{
				ProductInterface* prod = this->productFactory->getProductInstance(product);
				double productPrice = prod->getPrice();
				if (productPrice <= totalCoinsInHolder)
				{
					std::cout << "You have purchased a " << prod->getProductName() << "\n" << std::endl;
					double change = totalCoinsInHolder - productPrice;
					placeCoinsFromHolderToMachine();
					std::vector<InterfaceCoin*> changeCoins = getChange(change);
					for (auto& coin : changeCoins)
					{
						wallet->putCoin(*coin);
					}
					changeCoins.clear();
					(*productsWithCount)[product]--;
					std::cout << change << " returned as change.\n" << std::endl;
					delete prod;
					break;
				}
				else
				{
					std::cout << "Not enough credit. Insert more coins.\n" << std::endl;
				}
				delete prod;
			}
			else
			{
				std::cout << "Product not in stock.\n" << std::endl;
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
	std::vector<int> indicesToErase;
	std::sort(coinsInMachine->begin(), coinsInMachine->end(), [](InterfaceCoin* a, InterfaceCoin* b) {
		return a->getValue() < b->getValue();
		});
	for (int i = coinsInMachine->size() - 1; i >= 0; i--)
	{	
		if (value == 0) break;

		double coin = coinsInMachine->at(i)->getValue();
		if(value >= coin)
		{
			value -= coin;
			change.push_back(coinsInMachine->at(i));
			indicesToErase.push_back(i);
		}
	}
	for (int index : indicesToErase)
	{
		coinsInMachine->erase(coinsInMachine->begin() + index);
	}
	return change;
}