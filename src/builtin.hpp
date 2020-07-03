#pragma once
#include <iostream>
#include <string>
#include "command.hpp"
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
    static void execute(command comm);
    static bool isKnown(command comm);
};