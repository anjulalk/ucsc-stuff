// Add numbers until the user enters 1

#include <stdio.h>

int main(void) {
    int i = 1, sum = 0;
    
    do {
        // Get i from user
        printf("Enter a number: ");
        scanf("%d", &i);

        // Add i to sum
        sum += i;
    } while (i != 1);

    // Print the final result
    printf("Sum = %d\n", sum);

    return 0;
}