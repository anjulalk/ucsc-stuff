#include <stdio.h>

int fib(int k);

int main(void) {
    int i, j;
    printf("Upto which Fibonacci number do you want: ");
    scanf("%d", &i);

    for (j = 0; j < i; j++) {
        printf("%d\n", fib(j));
    }

    return 0;
}

int fib(int k) {
    if (k == 0) {
        return 1;
    }

    if (k == 1) {
        return 1;
    }

    return fib(k - 1) + fib(k - 2);
}