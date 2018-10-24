#include <stdio.h>
#include "mymalloc.h"

int main(void) {
    int *x = MyMalloc(20);
    x[0]  =1;

    char *p = MyMalloc(32);
    printf("%p\n", p);
    char *q = MyMalloc(32);
    printf("%p\n", q);
    char *r = MyMalloc(32);
    printf("%p\n", r);
    char *s = MyMalloc(32);
    printf("%p\n", s);
    char *t = MyMalloc(32);
    printf("%p\n", t);

    MyFree(r);
    r = MyMalloc(32);
    printf("%p\n", r);

    MyFree(r);
    MyFree(q);
    MyFree(s);
    s = MyMalloc(128);
    printf("%p\n", s);


}