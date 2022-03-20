#include "ProductFactory.h"

ProductInterface* ProductFactory::getProductInstance(std::string name)
{
	if(name.compare("burger"))
		return new Burger();

	if(name.compare("cola"))
		return new ColaSoda();
	
	if(name.compare("orange"))
		return new OrangeSoda();

	if(name.compare("chocolate"))
		return new Chocolate();

	return new ProductInterface();
}
