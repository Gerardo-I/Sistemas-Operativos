#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {

    pid_t pid;
    int fd;

    pid = fork();

    if (pid < 0) {
        perror("Error al crear el proceso");
        exit(1);
    }

    if (pid == 0) {  
        // Proceso hijo (M)

        fd = open("datos.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (fd < 0) {
            perror("Error al abrir archivo");
            exit(1);
        }

        int numeros[5] = {10, 20, 30, 40, 50};

        write(fd, numeros, sizeof(numeros));

        close(fd);

        printf("Hijo: escribió los números en datos.txt\n");
    }
    else {  
        // Proceso padre (Q)

        sleep(3);

        fd = open("datos.txt", O_RDONLY);

        if (fd < 0) {
            perror("Error al abrir archivo");
            exit(1);
        }

        int numeros[5];

        read(fd, numeros, sizeof(numeros));

        printf("Padre: datos leídos del archivo:\n");

        for (int i = 0; i < 5; i++) {
            printf("%d\n", numeros[i]);
        }

        close(fd);
    }

    return 0;
}