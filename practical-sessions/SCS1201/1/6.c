#include <stdio.h>

int main(void) {
    int n = 10;
    int *ptr_n = &n;

    *ptr_n += 1;

    if (ptr_n != &n) {
        printf("ptr_n is not equal to the address of n\n");        
        return 1;
    }
    if (*ptr_n != 11) {
        printf("ptr_n is not equal to 11\n");        
        return 1;
    }

    printf("Done!\n");
    return 0;
}