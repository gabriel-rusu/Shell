#include <iostream>
#include <string>
#include "src/command.hpp"

int main()
{

    std::string command_string;

    std::cout << "Welcome to Mini-Sell v.1" << std::endl;
    std::cout << "Enter your commands bellow" << std::endl;
    while (true)
    {
        std::cout << ">>>> ";
        std::getline(std::cin, command_string);
        std::cout << "Executing the command: " << command_string << std::endl;
        command entered_command(command_string);
        execute(entered_command);
        system(command_string.c_str());
    }

    return 0;
}
