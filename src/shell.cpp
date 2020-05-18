#include "shell.hpp"
#include <string>

using namespace std;


Shell::Shell(){
    command start_command("mini-shell");
    this->command_history.push_back(start_command);
}

bool Shell::execute(command entered_command){
    this->command_history.push_back(entered_command);
    return true;
}