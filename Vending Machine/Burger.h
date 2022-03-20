#pragma once
#include "ProductInterface.h"

class Burger: public ProductInterface
{
public:
	Burger() { this->name = "burger"; this->cost = 5.00; };
};

