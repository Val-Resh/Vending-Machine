#pragma once
#include "ProductInterface.h"

class Chocolate: public ProductInterface
{
public:
	Chocolate() { this->name = "chocolate"; this->cost = 2.50; };
};

