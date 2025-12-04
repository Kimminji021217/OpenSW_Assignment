#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>

int main(void){
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == 0){
        sleep(1);
        
        printf("Child process PID: %lu\nChild process PPID: %lu\n",
            (unsigned long)getpid(), (unsigned long)getppid());
        
        exit(7);
    }
    // int wstatus;
    // waitpid(child_pid, &wstatus, 0);
    // printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));

    printf("Parent process PID: %lu\nParent process PPID: %lu\n",
        (unsigned long)getpid(), (unsigned long)getppid());
    
    return 0;
}