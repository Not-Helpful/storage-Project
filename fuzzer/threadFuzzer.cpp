// C incs
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/user.h>

// C++ incs
#include <iostream>

// Push RAX
// Rax = 01
// Breakpoint
// Pop RAX



class Proc {
    public:
    pid_t childpid;
    enum class Status {RUNNING, STOPPED, KILLED};
    Status status;
    struct user_regs_struct regs;
    

    Proc(std::string filePath) {
        pid_t child = fork();

        if (child == 0) {
            ptrace(PTRACE_TRACEME, 0, NULL, NULL);
            execve(filePath.c_str(), NULL, NULL);
        }else {
            this->childpid = child;
            this->status = Proc::Status::STOPPED;
        }
    }
    void getRegs();
    void wait();
    void singleStep();
    void sysCallStep();
    void kill();
    void setRegs();
    void cont();

};

void Proc::getRegs() {
    ptrace(PTRACE_GETREGS, this->childpid, NULL, &this->regs);
}

void Proc::wait() {
    int status;
    int i = waitpid(this->childpid, &status, 0);
    // Check status and return appropriate I guess?
}

void Proc::singleStep() {
    ptrace(PTRACE_SINGLESTEP, this->childpid, NULL, NULL);
}

void Proc::sysCallStep() {
    ptrace(PTRACE_SYSCALL, this->childpid, NULL, NULL);
}

void Proc::kill() {
    ptrace(PTRACE_KILL, this->childpid, NULL, NULL);
}

void Proc::setRegs() {
    ptrace(PTRACE_SETREGS, this->childpid, NULL, &this->regs);
}

void Proc::cont() {
    ptrace(PTRACE_CONT, this->childpid, nullptr, nullptr);
}


int main() {
    Proc target = Proc(std::string("./target"));
    target.wait();
    target.cont();
    target.wait();
    target.getRegs();

    target.regs.rip = 0x00005555555551cd;

    for (int i = 0; i < 1000000; i++) {
        target.setRegs();
        
        target.cont();
        target.wait();
        target.cont();
        target.wait();
    }
    target.kill();
}