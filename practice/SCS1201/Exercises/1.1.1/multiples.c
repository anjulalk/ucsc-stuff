#include <stdio.h>
int mult3(int n);

int main(void) {
	printf("Multiples of x upto n^th multiple:\n\n");
	
	printf("x = ");
	int x;
	scanf("%d", &x);
	
	printf("n = ");
	int n;
	scanf("%d", &n);
	
	printf("\n");
	int i;
	for (i = 1; i <= n; i++) {
		printf("%d", mult(x, i));
		if (i != n) {
			printf(",\t");
		}
	}
	
	return 0;
}

int mult(int x, int n) {
	if (n == 1) {
		return x;
	}
	return x + mult(x, n - 1);
}
