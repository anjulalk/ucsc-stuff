#include <stdio.h>

int main(void) {
	int n1, n2, tot, *p1, *p2;
	
	printf("Input first number: ");
	scanf("%i", &n1);
	
	printf("Input second number: ");
	scanf("%i, ", &n2);
	
	p1 = &n1;
	p2 = &n2;
	
	tot = *p1 + *p2;
	printf("Sum: %i", tot);
	
	return 0;	
}
