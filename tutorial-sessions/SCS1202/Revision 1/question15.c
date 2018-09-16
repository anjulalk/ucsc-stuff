#include <stdio.h>

int main(void) {
    float p, t, r, simple_interest;
    printf("Input principal amount, rate of interest, time respectively: ");
    scanf("%f %f %f", &p, &t, &r);

    simple_interest = (p * t * r) / 100;
    printf("Simple interest: %f\n", simple_interest);

    return 0;
}