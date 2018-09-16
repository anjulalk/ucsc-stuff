#include <stdio.h>

int sum_h(int x);

int main(void) {
    printf("%d\n", sum_h(5));

    return 0;
}

int sum_h(int x) {
    if (x == 1) {
        return 1;
    }
    
    return (x + sum_h(x - 1));
}