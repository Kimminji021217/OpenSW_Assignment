#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void){
    sigset_t blockset, pendingset;

    sigemptyset(&blockset);
    sigaddset(&blockset, SIGINT);
    sigprocmask(SIG_BLOCK, &blockset, NULL);

    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");
    sleep(5);

    sigpending(&pendingset);

    if (sigismember(&pendingset, SIGINT)) {
        printf("SIGINT is pending\n");
    } else {
        printf("SIGINT is not pending\n");
    }

    return 0;
}