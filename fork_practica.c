#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = -1;
    int x = 5, y = 10;

    pid = fork();

    if (pid == 0){
        x = x + 10;
        y = y + 6;
        printf("Soy el hijo y mi pid = %d\n", getpid());
        printf("Variable x = %d, Variable y = %d\n", x, y);
        exit(0);
    }

    printf("Soy el padre y mi pid = %d\n", getpid());
    printf("Variable x = %d, Variable y = %d\n", x, y);
}