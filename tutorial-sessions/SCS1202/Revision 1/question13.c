#include <stdio.h>

int main(void) {
    int n, i;
    float sum = 0;

    printf("Please enter n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sum += 1 / (float) i;
    }

    printf("\n%f\n\n", sum);
    return 0;
}