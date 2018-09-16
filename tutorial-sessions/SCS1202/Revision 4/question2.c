#include <stdio.h>

int power(int, int);

int main(void) {
    int base = 2;
    int expo = 3;
    
    printf("%d\n", power(base, expo));

    return 0;
}

int power(int base, int expo) {
    if (expo == 0) return 1;
    
    return base * power(base, expo - 1);
}