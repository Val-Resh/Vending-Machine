#define _CRTDBG_MAP_ALLOC

#include "Wallet.h"
#include <stdlib.h> 
#include "ProductFactory.h"
#include "VendingMachine.h"
#include <iostream>
#include <vector>

const double COINS[6] = {0.01, 0.10, 0.20, 0.50, 1.00, 2.00};
void generateRandomCoins(std::vector<InterfaceCoin*> *coins, int numberOfCoins);

int main()
{
    std::map<std::string, int> vendingMachineProducts = { {"cola", 3}, {"burger", 4}, {"chocolate", 1}, {"orange", 5} };
    std::vector<InterfaceCoin*> vendingMachineStartingCoins;
    std::vector<InterfaceCoin*> userStartingCoins;
    generateRandomCoins(&vendingMachineStartingCoins, 15);
    generateRandomCoins(&userStartingCoins, 15);
    Wallet *wallet = new Wallet();

    for (auto &coin : userStartingCoins)
    {
        wallet->putCoin(coin);
    }
    wallet->displayWallet();

    VendingMachine* vendingMachine = new VendingMachine(&vendingMachineProducts, &vendingMachineStartingCoins);

    vendingMachine->displayProducts();
    delete vendingMachine;
    delete wallet;

    std::atexit([] {
        _CrtDumpMemoryLeaks();
        });
}

void generateRandomCoins(std::vector<InterfaceCoin*> *coins, int numberOfCoins)
{
    for (int i = 0; i < numberOfCoins; i++)
    {
        int randomIndex = rand() % sizeof(COINS) / sizeof(*COINS);
        coins->push_back(new PoundSterlingCoin(COINS[randomIndex]));
    }
}