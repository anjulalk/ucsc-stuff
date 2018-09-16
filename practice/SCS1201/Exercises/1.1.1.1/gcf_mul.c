// DSA 1 - Lecture 1 - Slide 75
// C Program to calculate the greatest common divisor of multiple integers

#include <stdio.h>
int gcf_mul_helper(int numbers[], int n);
int gcf_two(int a, int b);

int main(void) {
    // Variable initialization
    int n, i;

    // Get limit from the user
    printf("\nNumber limit: ");
    scanf("%d", &n);

    // Exit if n <= 1
    if (n <= 1) {
        printf("Invalid limit\n");
        return 1;
    }

    // Create array
    int numbers[n];

    printf("\n");

    // Get number inputs from user
    for (i = 0; i < n; i++) {
        printf("Number %d: ", i + 1); // To be user friendly
        scanf("%d", &numbers[i]);
    }
    
    printf("\nGCD of ");
    for (int i = 0; i < n; i++) {
        printf("%d", numbers[i]);
        if (i == n - 2) {
            printf(" and ");
        }
        else if (i < n - 1) {
            printf(", ");
        }
    }
    printf(" is %d\n", gcf_mul_helper(numbers, n));
}

int gcf_mul_helper(int numbers[], int n) {

    return 5;
}

int gcf_two(int a, int b) {
	if (b == 0) {
		return a;
	}
	
	return gcf_two(b, a % b);
}