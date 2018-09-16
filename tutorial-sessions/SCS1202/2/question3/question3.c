// Program to calculate the factorial of 10

#include <stdio.h>
#define MAX 10

int main(void) {
    int i = 1, fact = 1;

    while (i <= MAX) {
        fact *= i;
        i++;
    }

    printf("\nFactorial %d = %d\n", MAX, fact);

    return 0;
}