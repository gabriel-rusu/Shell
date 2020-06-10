#pragma once
#include <string>
#include <vector>
#include <iostream>

class Shell;

class command
{
private:
    std::vector<std::string> arguments;
    std::string command_name;
    void parse(std::string entered_command);
    friend Shell;

public:
    command(std::string command_string = "");
    bool operator==(command &new_command);
    friend std::ostream &operator<<(std::ostream &os,const command &comm);
    friend std::istream &operator>>(std::istream &is, command comm);
};