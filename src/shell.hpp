#include "command.hpp"
#include <vector>
#include <iostream>

class Shell
{
private:
    std::vector<command> command_history;
    command entered_command;
    bool search_known_commands();
    bool send_to_os();

public:
    Shell();
    bool execute();
    void run();
    friend std::istream &operator>>(std::istream& is,Shell &sh);
};