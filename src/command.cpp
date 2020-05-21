#include "command.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

command::command(string command_string)
{
    if (command_string.length())
        parse(command_string);
    else
    {
        this->arguments.push_back("'Nothing to be done!'");
        this->command_name = "echo";
    }
}

void command::parse(std::string entered_command)
{
    string argument;
    stringstream full_command(entered_command);
    full_command >> this->command_name;
    while (full_command >> argument)
        this->arguments.push_back(argument);
}

bool command::operator==(command &new_command)
{
    if (this->command_name != new_command.command_name)
        return false;
    vector<string> &args = new_command.arguments;
    for (string argument : arguments)
    {
        vector<string>::iterator found = find(args.begin(), args.end(), argument);
        if (found == new_command.arguments.end())
            return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const command &comm)
{

    os << comm.command_name << " ";
    for (string argument : comm.arguments)
        os << argument << " ";
    return os;
}