#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/user.h>

#include <iostream>

int main() {
    asm("int $3\n");
    printf("Hello World\n");
    raise(SIGINT);
}