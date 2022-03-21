# Vending Machine 
## The processes of a vending machine simulated in C++

The processes run in the command line.
The `Vending Machine.sln` file contains the solution for Visual Studio, use it to open the project which should structure the project folders. 
Within this environment it is possible to run the program. Otherwise, use a compiler of your choice to compile the code.

____________________________

## Demo:

*insert image here*

Commands work as intended. Follow instructions to use.

____________________________

## Concerns:

* `Dynamic Memory Allocation:` I've decided to manually allocate and manage memory. This is isn't exactly a concern, but rather a choice. The danger are memory leaks, yet I've ensured that no memory leaks happen in the program. All memory is released.  
I could have used the stack and smart pointers for certain variables, yet prefered to use regular pointers and the heap.
Felt more like my style, but in the future I will consider the other options available in C++.
* `VendingMachine::GetChange()`

