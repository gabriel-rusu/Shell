#include <iostream>
#include <string>
#include "src/command.hpp"
#include "src/shell.hpp"

void init();

int main()
{
    shell current_shell;
    
    current_shell.init();
    current_shell.start();
}

