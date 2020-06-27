#include "shell.hpp"
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

bool shell::execute(const command &comm)
{
    execvp(comm.getCommandName(), comm.getArguments());
}
bool shell::init()
{
    this->pid = getpid();
    this->state = IDLE;
}
bool shell::start()
{
    this->state = RUNNING;
    command comm;
    cout << "~>";
    while (cin>>comm)
    {
        this->create_in_subshell(comm);
        cout << "~>"
    }
}

bool create_in_subshell(const command &comm)
{
    int pid = fork();
    if (pid > 0)
    {
        wait(pid);
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