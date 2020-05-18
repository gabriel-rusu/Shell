#include "command.hpp"
#include <vector>
#include <iostream>

class Shell
{
private:
    std::vector<command> command_history;

public:
    Shell();
    bool execute(command entered_command);
};