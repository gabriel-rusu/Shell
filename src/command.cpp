#include "command.hpp"

using namespace std;

command::command(string command_string)
{
    if (command_string.length())
        parse(command_string);
    else {
        this->arguments.push_back("'Nothing to be done!'");
        this->command_name = "echo";
    }
}

void command::parse(std::string entered_command){

}

void execute(command entered_command){
    
}

