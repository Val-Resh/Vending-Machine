# Vending Machine 
## The processes of a vending machine simulated in C++

The processes run in the command line.
The `Vending Machine.sln` file contains the solution for Visual Studio, use it to open the project which should structure the project folders. 
Within this environment it is possible to run the program. Otherwise, use a compiler of your choice to compile the code.

____________________________

## Demo:

![Demo](https://github.com/Val-Resh/Vending-Machine/blob/main/DemoImage/Demo.JPG)

Commands work as intended. Follow instructions to use.

____________________________

## Concerns:

* **`Dynamic Memory Allocation:`** I've decided to manually allocate and manage memory. This is isn't exactly a concern, but rather a choice. The danger are memory leaks, yet I've ensured that no memory leaks happen in the program. All memory is released.  
I could have used the stack and smart pointers for certain variables, yet prefered to use regular pointers and the heap.
Felt more like my style, but in the future I will consider the other options available in C++.

* **`std::vector<InterfaceCoin*> VendingMachine::getChange(double value):`** This method currently runs at `O(n log n)` as it sorts the coins in machine before computing which coins should be returned as change. I've considered whether it would be possible to reduce it to `O(n)`. It is possible, but it would reduce the functionality. The coins would be randomly picked, instead of picking the least amount of coins to return as change. 

* ~~**`double VendingMachine::calculateCoinsInHolder()`**: This computation is repeated each time a new coin is added.  This isn't effecient. Instead, I am considering to add a `double` variable to keep track of the coins inserted. Should be a simple refactor.~~ 

* **`Precision`**: Working with money precision is highly important. The `double` type is not precise which can lead to loss of data when calculating the change. At the moment I am not considering increasing precision as this is a mock project.

## Updates

* `double VendingMachine::calculateCoinsInHolder()` method removed from codebase. It was replaced with an attribute value on the stack to keep track of the coins in holder. This reduces unnecessary computation.