#include "shell.hpp"
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include "builtin.hpp"
#include <sys/wait.h>
#include <vector>
#include <sstream>

using namespace std;

bool shell::execute(simple_command command)
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
    std::cout << "Welcome to Mini-Sell v3.0" << std::endl;
    std::cout << "Enter your commands bellow" << std::endl;
    this->state = RUNNING;
    string command_string;
    cout << "~> ";
    while (getline(cin, command_string))
    {
        if (shell::analyze(command_string) == SINGLE_COMMAND)
        {
            this->create_in_subshell(simple_command(command_string));
        }
        else
        {
            vector<simple_command> commands = shell::split(command_string);
            int length = commands.size();
            int *pipes[length - 1];
            for (int *&spipe : pipes)
            {
                spipe = new int[2];
                pipe(spipe);
            }

            for (int index = 0; index < length; index++) //TODO: add support for unlimited processes in a piped command
            {
                int std_in, std_out;
                std_in = index != 0 ? pipes[index - 1][0] : -1;
                std_out = index + 1 < length ? pipes[index][1] : -1;
                this->create_in_subshell(commands[index], std_in, std_out);
            }
            for (auto pipe : pipes)
            {
                close(pipe[0]);
                close(pipe[1]);
            }
        }
        cout << "~> ";
    }
    return true;
}

bool shell::create_in_subshell(simple_command command)
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

int shell::analyze(string &command)
{
    return command.find("|") != string::npos ? COMPOUND_COMMAND : SINGLE_COMMAND;
}

vector<simple_command> shell::split(string &command)
{
    vector<simple_command> result;
    stringstream ss(command);
    string word, current_command = "";
    while (ss >> word)
    {
        if (word == "|")
        {
            result.push_back(current_command);
            current_command = "";
        }
        else
        {
            current_command += (word + " ");
        }
    }
    if (current_command.size() != 0)
        result.push_back(current_command);
    return result;
}

bool shell::create_in_subshell(simple_command command, int input_fd, int output_fd)
{
    int pid = fork();
    if (pid == 0)
    {
        if (input_fd > 0)
            dup2(input_fd, STDIN_FILENO);
        if (output_fd > 0)
            dup2(output_fd, STDOUT_FILENO);
        shell sub_shell;
        sub_shell.execute(command);
        return true;
    }
    else if (pid > 0)
    {
        wait(NULL);
        if (input_fd > 0)
            close(input_fd);
        if (output_fd > 0)
            close(output_fd);
        return true;
    }
    return false;
}