#include <iostream>
#include <string>
#include "src/command.hpp"
#include "src/shell.hpp"

int main()
{

    std::string command_string;
    Shell shell;

    std::cout << "Welcome to Mini-Sell v.1" << std::endl;
    std::cout << "Enter your commands bellow" << std::endl;
    while (true)
    {
        std::cout << "~>";
        std::getline(std::cin, command_string);
        std::cout << "Executing the command: " << command_string << std::endl;
        shell.execute(command_string);
        system(command_string.c_str());
    }

    return 0;
}
