#pragma once
#include "utils.hpp"
#include <utility>
#include <iostream>
#include <string>
#include <vector>

class simple_command
{
private:
    std::string commandName;
    std::vector<std::string> arguments;
    std::pair<std::string, std::vector<std::string>> parseRaw(std::string command_string);
    bool assign(std::string &command_string);

public:
    simple_command(std::string = "");
    friend std::istream &operator>>(std::istream &is, simple_command &newCommand);
    friend std::ostream &operator<<(std::ostream &os, const simple_command &command);
    char *const *getArguments();
    const char *getCommandName();
    operator std::string() const;
    operator const char *() const;
};