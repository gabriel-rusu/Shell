#include <iostream>
#include <string>

int main()
{

    std::string command;

    std::cout << "Welcome to Mini-Sell v.1" << std::endl;
    std::cout << "Enter your commands bellow" << std::endl;
    while (true)
    {
        std::cout << ">>>> ";
        std::getline(std::cin, command);
        std::cout << "Executing the command: " << command << std::endl;
        system(command.c_str());
    }

    return 0;
}