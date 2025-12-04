#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <program> [OPTION]...\n", argv[0]);
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {
        execve(argv[1], &argv[1], NULL);  
        exit(1);
    }

    int wstatus;
    waitpid(pid, &wstatus, 0);

    printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));

    return 0;
}
