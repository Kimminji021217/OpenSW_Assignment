#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int mysystem(const char* command) {
    if (command == NULL) return 1;

    pid_t pid = fork();

    if (pid == 0) {
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);
        exit(1);
    }

    int status;
    waitpid(pid, &status, 0);

    return WEXITSTATUS(status);
}

int main(void) {
    system("ls -l | wc -l");
    system("find . -name '*.c'");

    // mysystem("ls -l | wc -l");
    // mysystem("find . -name '*.c'");

    printf("Good Bye~\n");
    
    return 0;
}