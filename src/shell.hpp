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
    bool create_in_subshell(simple_command command);
    bool create_in_subshell(simple_command command, int input_fd, int output_fd);

public:
    bool execute(simple_command command);
    bool init();
    bool start();
    static int analyze(std::string &command);
    static std::vector<simple_command> split(std::string &command);
};