#pragma once
#include <string>
#include <vector>
#include <iostream>

class command
{
private:
    std::vector<std::string> arguments;
    std::string command_name;
    void parse(std::string entered_command);

public:
    command(std::string command_string = "");
    friend void execute(command entered_command);
};