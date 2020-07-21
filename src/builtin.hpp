#pragma once
#include <iostream>
#include <string>
#include "simple_command.hpp"
#include "utils.hpp"
#include <map>

class builtin
{
private:
    std::map<std::string, int> knownCommands;
    static builtin *instance;
    builtin();
    static builtin *getInstance();

public:
    static void execute(simple_command command);
    static bool isKnown(simple_command command);
};