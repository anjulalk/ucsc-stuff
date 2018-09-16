#include <stdio.h>
long factorial(int m);

int main(void) {
    //Get numerical input from the user
    printf("Factorial of: ");
    int a;
    scanf("%d", &a);
    if (a > 0) {
        //Proceed if number is positive
        printf("%li\n", factorial(a));
    }
    else {
        //If negative or zero, return 1
        printf("Error: Number should be positive.\n");
        return 1;
    }
}

long factorial(int m) {
    if (m == 1) {
        //Factorial of 1 = 1
        return 1;
    }
    else {
        //Recall the function itself
        return m * factorial(m - 1);
    }
}
