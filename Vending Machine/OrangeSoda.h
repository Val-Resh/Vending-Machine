#pragma once
#include "ProductInterface.h"
class OrangeSoda: public ProductInterface
{
public:
	OrangeSoda() { this->name = "orange"; this->cost = 0.90; };
};

