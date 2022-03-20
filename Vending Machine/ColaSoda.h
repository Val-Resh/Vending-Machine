#pragma once
#include "ProductInterface.h"

class ColaSoda: public ProductInterface
{
public:
	ColaSoda() { this->name = "cola"; this->cost = 0.80; };
};

