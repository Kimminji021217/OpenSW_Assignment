#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/syscall.h>

struct two_double {
    double a;
    double b;
};
struct two_double data;

void sigint_handler(int _signo) {
    printf("%f, %f\n", data.a, data.b);;
    alarm(1);
}

int main(void) {   

    struct sigaction sa_sigalrm;
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};
    sigset_t blockset, oldset;

    sa_sigalrm.sa_handler = sigint_handler;
    sigemptyset(&sa_sigalrm.sa_mask);
    sa_sigalrm.sa_flags = 0;

    if (sigaction(SIGALRM, &sa_sigalrm, NULL) == -1) {
        perror("sigaction error: ");
        exit(0);
    }

    sigemptyset(&blockset);
    sigaddset(&blockset, SIGALRM);
    
    alarm(1);
    while (1) {
        //block SIGALARM signal
        sigprocmask(SIG_BLOCK, &blockset, &oldset);
        data = ones;
        //unblock SIGALARM signal
        sigprocmask(SIG_SETMASK, &oldset, NULL);

        //block SIGALARM signal
        sigprocmask(SIG_BLOCK, &blockset, &oldset);
        data = zeros;

        //unblock SIGALARM signal
        sigprocmask(SIG_SETMASK, &oldset, NULL);
    }

    return 0;
}
