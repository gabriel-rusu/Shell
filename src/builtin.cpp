#include "builtin.hpp"
#include <unistd.h>
#include <sys/resource.h>

using namespace std;

builtin *builtin::instance = nullptr;

builtin *builtin::getInstance()
{
    if (builtin::instance != nullptr)
        return instance;
    else
        return instance = new builtin();
}

void builtin::execute(simple_command command)
{
    builtin *instance = builtin::getInstance();
    int pid;
    int which = PRIO_PROCESS;
    if (!builtin::isKnown(command))
        return;
    switch (instance->knownCommands[command])
    {
    case CHDIR:
        chdir(command);
        break;
    case SETPRIORITY:
        pid = getpid();
        int ret = setpriority(which, pid, atoi(command));
        if(ret == -1){
            cout<<"Failed to change the priority of process with PID "<<pid<<endl;
            cout<<"Error no is: "<<errno<<endl;
        }else {
            cout<<"Priority changed"<<endl;
        }
        break;
    }
}
bool builtin::isKnown(simple_command command)
{
    builtin *instance = builtin::getInstance();
    return instance->knownCommands.find(command) != instance->knownCommands.end();
}

builtin::builtin()
{
    knownCommands["cd"] = CHDIR;
    knownCommands["setuid"] = SETUID;
    knownCommands["setguid"] = SETGUID;
    knownCommands["setpriority"] = SETPRIORITY;
    knownCommands["symlink"] = SYMLINC;
};