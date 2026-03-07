#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

    pid_t t, w, v, s, l, p;

    printf("Proceso R -> PID: %d, Padre: %d\n", getpid(), getppid());

    t = fork();

    if(t == 0){
        // Proceso T
        printf("Proceso T -> PID: %d, Padre: %d\n", getpid(), getppid());

        v = fork();

        if(v == 0){
            // Proceso V
            printf("Proceso V -> PID: %d, Padre: %d\n", getpid(), getppid());
            exit(0);
        }

        exit(0);
    }

    w = fork();

    if(w == 0){
        // Proceso W
        printf("Proceso W -> PID: %d, Padre: %d\n", getpid(), getppid());

        s = fork();

        if(s == 0){
            // Proceso S
            printf("Proceso S -> PID: %d, Padre: %d\n", getpid(), getppid());
            exit(0);
        }

        l = fork();

        if(l == 0){
            // Proceso L
            printf("Proceso L -> PID: %d, Padre: %d\n", getpid(), getppid());

            p = fork();

            if(p == 0){
                // Proceso P
                printf("Proceso P -> PID: %d, Padre: %d\n", getpid(), getppid());
                exit(0);
            }

            exit(0);
        }

        exit(0);
    }

    return 0;
}