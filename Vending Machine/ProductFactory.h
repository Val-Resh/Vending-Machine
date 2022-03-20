#pragma once
#include "ColaSoda.h"
#include "OrangeSoda.h"
#include "Burger.h"
#include "Chocolate.h"

/*
* Factory responsible for creating instances of product objects.
*/
class ProductFactory
{
public:
	ProductFactory() {};
	ProductInterface* getProductInstance(std::string name);
};

