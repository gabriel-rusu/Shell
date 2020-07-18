#pragma once
#include <iostream>
#include "simple_command.hpp"

class shell
{
private:
    const int IDLE = 0;
    const int RUNNING = 1;

    int pid;
    int state;
    bool create_in_subshell(simple_command &command);

public:
    bool execute(simple_command &command);
    bool init();
    bool start();
};