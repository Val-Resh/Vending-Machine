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
bool validateFirstInput(std::string input);
bool executeCommand(int input);
bool validateCoinInput(std::string input);
void displayCommands();
void pintInvalidCommand();
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
        std::string input;
        std::cout << "Select a command!" << std::endl;
        std::cin >> input;
        if (validateFirstInput(input))
        {
            int convertedInput = std::stoi(input);
            if (!executeCommand(convertedInput))
                break;
        }
        else
        {
            pintInvalidCommand();
        }
    }

    delete wallet;
    delete vendingMachine;

    /*
    std::atexit([] {
        _CrtDumpMemoryLeaks();
        });
        */
}

void pintInvalidCommand()
{
    std::cout << "Invalid Command!\n" << std::endl;
}

bool validateFirstInput(std::string input)
{   
    try
    {
        std::stoi(input);
        return true;
    }
    catch (const std::invalid_argument& error)
    {
        return false;
    }
}

bool validateCoinInput(std::string input)
{
    try
    {
        std::stod(input);
        return true;
    }
    catch (const std::invalid_argument& error)
    {
        return false;
    }
}

bool executeCommand(int input)
{
    switch (input)
    {
    case 1:
    {
        std::string coin;
        std::cout << "Which coin would you like to insert?" << std::endl;
        std::cin >> coin;
        if (validateCoinInput(coin))
        {
            InterfaceCoin* poundCoin = wallet->retrieveCoin(std::stod(coin));
            vendingMachine->insertCoin(poundCoin);
            std::cout << poundCoin->getValue() << " coin inserted\n" << std::endl;
        }
        else
        {
            pintInvalidCommand();
        }
        return true;
        break;
    }
    case 2:
    {
        std::string product;
        std::cout << "Which item would you like to buy?" << std::endl;
        std::cin >> product;
        vendingMachine->purchaseProduct(wallet, product);
        return true;
        break;
    }
    case 3:
    {
        vendingMachine->cancel(wallet);
        std::cout << "Coins returned.\n" << std::endl;
        return true;
        break;
    }
    case 4:
        return false;
        break;

    default:
        return true;
        break;
    }
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
