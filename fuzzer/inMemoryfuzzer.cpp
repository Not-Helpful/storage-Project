#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/user.h>
#include <stdio.h>


int fuzzer() {
    return 0;
}


int main() {
    for (int i = 0; i < 1000000; i++) {
        fuzzer();
        printf("Hello World\n");
        fuzzer();
    }
}