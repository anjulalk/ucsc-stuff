// Calculates the sum of the first 10 natural numbers

#include <stdio.h>

int main(void) {
    // Initiate variables
    int i, j = 0;

    // Iterate over i, and add it to j
    for (i = 1; i <= 10; i++) {
        j += i;
    }

    // Print the result
    printf("Sum = %d\n", j);

    return 0;
}