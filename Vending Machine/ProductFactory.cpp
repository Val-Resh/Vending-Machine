#include "ProductFactory.h"

ProductInterface* ProductFactory::getProductInstance(std::string name)
{
	if(name == "burger")
		return new Burger();

	else if(name == "cola")
		return new ColaSoda();
	
	else if(name == "orange")
		return new OrangeSoda();

	else if(name == "chocolate")
		return new Chocolate();

	else  return new ProductInterface();
}
