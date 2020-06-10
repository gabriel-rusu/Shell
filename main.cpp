#include <iostream>
#include <string>
#include "src/command.hpp"
#include "src/shell.hpp"

void init();

int main()
{
    Shell shell;
    
    shell.init();
    shell.start();
}

