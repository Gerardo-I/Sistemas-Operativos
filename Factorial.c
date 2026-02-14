#include <stdio.h>

long factorial(int n) {
    if (n < 0) {
        return -1; 
    }

    long result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    long result = factorial(number);

    if (result == -1) {
        printf("Negative numbers can't be used.\n");
    } else {
        printf("The factorial of %d is: %lld\n", number, result);
    }

    return 0;
}