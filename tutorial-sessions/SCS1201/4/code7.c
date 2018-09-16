#include <stdio.h>
void swap(int *p, int *q);

int main(void) {
	int a = 5, b = 10;
	printf("a = %i\tb = %i\n", a, b);
	
	printf("Swapping..\n");
	swap(&a, &b);
	
	printf("a = %i\tb = %i\n", a, b);
	return 0;
}

void swap(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
	
	return;
}
