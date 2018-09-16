#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, *p, i, sum = 0;
    
    printf("Number of elements: ");
    scanf("%i", &n);

    //allocate memory for n number of ints
    p = malloc(sizeof(int) * n);
    if (p == NULL) {
        printf("Unable to allocate memory..\n");
        return 1;
    }

    //scan elements
    printf("Enter elements of array: \n");
    for (i = 0; i < n; i++) {
        scanf("%i", p + i);
        sum += *(p + i);
    }

    printf("Sum = %i\n", sum);
    free(p);
    return 0;   
}