#include "shell.hpp"
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include "builtin.hpp"
#include <sys/wait.h>

using namespace std;

bool shell::execute(simple_command &command)
{
    if (builtin::isKnown(command))
        builtin::execute(command);
    else
        execvp(command.getCommandName(), command.getArguments());
    return true;
}
bool shell::init()
{
    this->pid = getpid();
    this->state = IDLE;
    return true;
}
bool shell::start()
{
    std::cout << "Welcome to Mini-Sell v2.1" << std::endl;
    std::cout << "Enter your commands bellow" << std::endl;
    this->state = RUNNING;
    simple_command command;
    cout << "~>";
    while (cin >> command)
    {
        this->create_in_subshell(command);
        cout << "~>";
    }
    return true;
}

bool shell::create_in_subshell(simple_command &command)
{
    int pid = fork();
    if (pid > 0)
    {
        wait(NULL);
        return true;
    }
    else if (pid == 0)
    {
        shell sub_shell;
        sub_shell.execute(command);
        return true;
    }
    else
    {
        cout << "Error executing the command: " << command << endl;
        return false;
    }
}