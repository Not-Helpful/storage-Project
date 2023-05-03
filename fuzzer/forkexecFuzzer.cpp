#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/user.h>
#include <stdio.h>


int main() {
    for (int i = 0; i < 1000000; i++) {
        pid_t childpid = fork();
        if (childpid == 0) {
            ptrace(PTRACE_TRACEME, 0, NULL, NULL);
            execve("./target", NULL, NULL);

        } else {
            int status;
            int i = waitpid(childpid, &status, 0);
            ptrace(PTRACE_CONT, childpid, nullptr, nullptr);
            i = waitpid(childpid, &status, 0);
            ptrace(PTRACE_CONT, childpid, nullptr, nullptr);
            i = waitpid(childpid, &status, 0);
            ptrace(PTRACE_CONT, childpid, nullptr, nullptr);
            i = waitpid(childpid, &status, 0);
        }
    }
}