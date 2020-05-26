#include "shell.hpp"
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

Shell::Shell()
{
    command start_command("mini-shell");
    this->command_history.push_back(start_command);
}

bool Shell::execute(command comm)
{
    this->entered_command = comm;
    this->command_history.push_back(this->entered_command);
    if (search_known_commands())
        return true;
    return send_to_os();
}

std::istream &operator>>(std::istream &is, Shell &sh)
{
    string command_string;
    getline(is, command_string);
    sh.entered_command = command_string;
    return is;
}

bool Shell::search_known_commands()
{
    command cmd = string("history");
    if (this->entered_command == cmd)
    {
        for (command comm : this->command_history)
            cout << comm << endl;
        return true;
    }
    return false;
}

bool Shell::send_to_os()
{
    char *cmd = const_cast<char *>(entered_command.command_name.c_str());
    int len = entered_command.arguments.size();
    char **argv = new char *[len + 2];
    argv[0] = cmd;
    for (int i = 1; i < len + 1; i++)
        argv[i] = const_cast<char *>(entered_command.arguments[i - 1].c_str());
    argv[len + 1] = NULL;
    int pid = fork();
    if (pid == 0)
        execvp(cmd, argv);
    else if (pid > 0)
        wait(NULL);
    else
        cout << "Error executing the task";
    return true;
}

<<<<<<< HEAD
void Shell::run()
{
=======
void Shell::init()
{
    std::cout << "Welcome to Mini-Sell v1.2" << std::endl;
    std::cout << "Enter your commands bellow" << std::endl;
}

void Shell::start(){
>>>>>>> 6bdc2d810b3bc1feaffba04aacabae1eeba858c1
    string command_string;
    while (true)
    {
        std::cout << "~>";
<<<<<<< HEAD
        getline(cin, command_string);
        this->entered_command = command_string;
        this->execute();
=======
        getline(cin,command_string);
        this->execute(command_string);
>>>>>>> 6bdc2d810b3bc1feaffba04aacabae1eeba858c1
    }
}