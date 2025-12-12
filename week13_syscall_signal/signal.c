#include <stdio.h>
#include <unistd.h>

int main(void){

    for (;;) {
        printf("pid: %d\n", getpid());
        sleep(1);
    }

    return 0;
}