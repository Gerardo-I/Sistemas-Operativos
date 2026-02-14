#include <stdio.h>
#include <stdbool.h>
bool Prime_num(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int number = 20;
    int isPrime = number + 1;

    while (!Prime_num(isPrime)) {
        isPrime++;
    }

    printf("The first prime number over %d is: %d\n", number, isPrime);

    return 0;
}