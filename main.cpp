#include <iostream>
#include <string>
#include "src/command.hpp"
#include "src/shell.hpp"

void init();

int main()
{
    Shell shell;
    
    init();
    shell.run();
}

void init()
{
    std::cout << "Welcome to Mini-Sell v1.2" << std::endl;
    std::cout << "Enter your commands bellow" << std::endl;
}