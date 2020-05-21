#include <iostream>
#include <string>
#include "src/command.hpp"
#include "src/shell.hpp"

void init();

int main()
{
    Shell shell;
    init();

    while (true)
    {
        std::cout << "~>";
        std::cin >> shell;
        shell.execute();
    }
    return 0;
}

void init()
{
    std::cout << "Welcome to Mini-Sell v1.2" << std::endl;
    std::cout << "Enter your commands bellow" << std::endl;
}