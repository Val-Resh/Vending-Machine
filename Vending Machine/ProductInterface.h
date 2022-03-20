#pragma once
#include <string>

/*
* The product interface.
* Every product in the vending machine implements this class.
*/
class ProductInterface
{
private:
	std::string defaultName = "none";
	double defaultCost = 0.00;

public:
	ProductInterface() { this->name = this->defaultName; this->cost = this->defaultCost; };
	std::string getProductName() { return this->name; };
	double getPrice() { return this->cost; };
	void updatePrice(double newPrice) { this->cost = newPrice; };

protected:
	std::string name;
	double cost;
};

