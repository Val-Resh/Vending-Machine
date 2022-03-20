#define _CRTDBG_MAP_ALLOC

#include "Wallet.h"
#include <stdlib.h> 
#include "ProductFactory.h"
#include "VendingMachine.h"
#include <iostream>
#include <vector>
#include "PoundSterlingCoin.h"
#include <map>

const double COINS[6] = {0.01, 0.10, 0.20, 0.50, 1.00, 2.00};
const int MAX_STARTING_COINS = 15;

void generateRandomCoins(std::vector<InterfaceCoin*> *coins, int numberOfCoins);
void displayCommands();
std::map<std::string, int> *vendingMachineProducts = new std::map<std::string, int> { {"cola", 3}, {"burger", 4}, {"chocolate", 1}, {"orange", 5} };
std::vector<InterfaceCoin*> *vendingMachineStartingCoins = new std::vector<InterfaceCoin*>();
std::vector<InterfaceCoin*> *userStartingCoins = new std::vector<InterfaceCoin*>();;
Wallet* wallet;
VendingMachine* vendingMachine;


int main()
{
    generateRandomCoins(vendingMachineStartingCoins, MAX_STARTING_COINS);
    generateRandomCoins(userStartingCoins, MAX_STARTING_COINS);

    wallet = new Wallet(userStartingCoins);
    vendingMachine = new VendingMachine(vendingMachineProducts, vendingMachineStartingCoins);

    while (true)
    {
        displayCommands();
        break;
    }

    delete wallet;
    delete vendingMachine;

    std::atexit([] {
        _CrtDumpMemoryLeaks();
        });
}


void displayCommands()
{   
    wallet->displayWallet();
    std::cout << "Products in Vending Machine:" << std::endl;
    vendingMachine->displayProducts();
    std::cout << std::endl;
    vendingMachine->displayCoinsInHolder();
    std::cout << std::endl << "Commands:\n"
        << "1 - Insert coin.\n"
        << "2 - Purchase product.\n"
        << "3 - Cancel.\n"
        << "4 - Exit.\n";
}
void generateRandomCoins(std::vector<InterfaceCoin*> *coins, int numberOfCoins)
{
    for (int i = 0; i < numberOfCoins; i++)
    {
        int randomIndex = rand() % sizeof(COINS) / sizeof(*COINS);
        coins->push_back(new PoundSterlingCoin(COINS[randomIndex]));
    }
}