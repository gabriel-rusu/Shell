#include "shell.hpp"
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

bool shell::execute(command &comm)
{
    execvp(comm.getCommandName(), comm.getArguments());
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
    std::cout << "Welcome to Mini-Sell v2.0" << std::endl;
    std::cout << "Enter your commands bellow" << std::endl;
    this->state = RUNNING;
    command comm;
    cout << "~>";
    while (cin >> comm)
    {
        this->create_in_subshell(comm);
        cout << "~>";
    }
    return true;
}

bool shell::create_in_subshell(command &comm)
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
        sub_shell.execute(comm);
        return true;
    }
    else
    {
        cout << "Error executing the command: " << comm << endl;
        return false;
    }
}