#include <stdio.h>
int gcf(int a, int b);

int main(void) {
	printf("Greatest Common Factor\n\n");
	
	int a, b;
	printf("Number 1: ");
	scanf("%d", &a);
	printf("Number 2: ");
	scanf("%d", &b);
	
	printf("\nGCF of %d and %d is %d\n", a, b, gcf(a,b));
	return 0;
}

int gcf(int a, int b) {
	if (b == 0) {
		return a;
	}
	
	return gcf(b, a % b);
}

