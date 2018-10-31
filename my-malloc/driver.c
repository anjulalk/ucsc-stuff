#include <stdio.h>
#include "mymalloc.h"

int main(void) {
    char *p = MyMalloc(32);
    char *q = MyMalloc(32);
    char *r = MyMalloc(32);

    drawMem();

    MyFree(q);
    MyFree(p);
    MyFree(r);
    drawMem();
}