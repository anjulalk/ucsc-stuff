#include <stdio.h>

int main(void) {
    int fcount = 0, i = 1;

    while (fcount != 3) {
        if ((i % 8 == 0) && (i % 12 == 0)) {
            printf("%d\n", i);
            fcount++;
        }
        i++;
    }

    return 0;
}