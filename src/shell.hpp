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
<<<<<<< HEAD
    bool execute();
    void run();
=======
    bool execute(command comm);
>>>>>>> 6bdc2d810b3bc1feaffba04aacabae1eeba858c1
    friend std::istream &operator>>(std::istream& is,Shell &sh);
    void init();
    void start();
};