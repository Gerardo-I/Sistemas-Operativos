#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void verificar_error(int valor, const char *mensaje) {
    if (valor < 0) {
        switch (errno) {
            case EAGAIN:
                fprintf(stderr, "%s: Recurso temporalmente no disponible (EAGAIN)\n", mensaje);
                break;
            case EACCES:
                fprintf(stderr, "%s: Permiso denegado (EACCES)\n", mensaje);
                break;
            case EBADF:
                fprintf(stderr, "%s: Descriptor de archivo inválido (EBADF)\n", mensaje);
                break;
            default:
                perror(mensaje);
        }
        exit(EXIT_FAILURE);
    }
}

void escribir_datos() {
    int fd;
    float numeros[] = {1.5, 2.3, 3.7, 4.1, 5.9};

    fd = open("datos.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    verificar_error(fd, "Error al abrir datos.txt");

    int n = write(fd, numeros, sizeof(numeros));
    verificar_error(n, "Error al escribir datos.txt");

    close(fd);
}


void leer_datos() {
    int fd;
    float numeros[5];

    fd = open("datos.txt", O_RDONLY);
    verificar_error(fd, "Error al abrir datos.txt");

    int n = read(fd, numeros, sizeof(numeros));
    verificar_error(n, "Error al leer datos.txt");

    for (int i = 0; i < 5; i++) {
        printf("Numero %d: %.2f\n", i+1, numeros[i]);
    }

    close(fd);
}


void escribir_datos2() {
    int fd;
    float numeros[5] = {10.1, 20.2, 30.3, 40.4, 50.5};

    fd = open("datos2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    verificar_error(fd, "Error al abrir datos2.txt");

    for (int i = 0; i < 5; i++) {
        int n = write(fd, &numeros[i], sizeof(float));
        verificar_error(n, "Error al escribir datos2.txt");

        printf("Bytes escritos (n) en iteracion %d: %d\n", i+1, n);
    }

    close(fd);
}


void leer_datos2() {
    int fd;
    float numero;

    fd = open("datos2.txt", O_RDONLY);
    verificar_error(fd, "Error al abrir datos2.txt");

    while (read(fd, &numero, sizeof(float)) > 0) {
        printf("Numero leido: %.2f\n", numero);
    }

    close(fd);
}


int main() {
    escribir_datos();
    leer_datos();
    escribir_datos2();
    leer_datos2();
    return 0;
}