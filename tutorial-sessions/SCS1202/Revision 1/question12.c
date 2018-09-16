#include <stdio.h>

int main(void) {
    int i, j;
    printf("Input a number: ");
    scanf("%d", &i);

    for (j = 1; j <= 12; j++) {
        printf("%d x %2d = %2d\n", i, j, i * j);
    }

    return 0;
}