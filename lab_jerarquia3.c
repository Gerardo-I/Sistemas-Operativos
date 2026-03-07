#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    pid_t pid1, pid2;

    pid1 = fork();

    if(pid1 == 0){
        // Proceso N (pares)
        FILE *f = fopen("N.txt","w");

        for(int i=1;i<=10;i++){
            fprintf(f,"%d\n", i*2);
        }

        fclose(f);
        exit(0);
    }

    pid2 = fork();

    if(pid2 == 0){
        // Proceso M (impares)
        FILE *f = fopen("M.txt","w");

        for(int i=0;i<10;i++){
            fprintf(f,"%d\n", i*2+1);
        }

        fclose(f);
        exit(0);
    }

    // Padre R espera a los hijos
    wait(NULL);
    wait(NULL);

    FILE *f1 = fopen("N.txt","r");
    FILE *f2 = fopen("M.txt","r");

    int pares[10], impares[10];

    for(int i=0;i<10;i++){
        fscanf(f1,"%d",&pares[i]);
        fscanf(f2,"%d",&impares[i]);
    }

    fclose(f1);
    fclose(f2);

    printf("Resultados:\n");

    for(int i=0;i<10;i++){
        printf("%d + %d = %d\n", impares[i], pares[i], impares[i]+pares[i]);
    }

    return 0;
}