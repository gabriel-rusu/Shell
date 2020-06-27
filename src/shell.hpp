#pragma once
#include <iostream>
#include "command.hpp"

class shell
{
private:
    const int IDLE = 0;
    const int RUNNING = 1;

    int pid;
    int state;
    bool create_in_subshell(const command &comm);

public:
    bool execute(const command &comm);
    bool init();
    bool start();
}