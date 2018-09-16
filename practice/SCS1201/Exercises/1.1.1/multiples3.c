#include <stdio.h>
int mult3(int n);

int main(void) {
	printf("Multiples of 3 upto n^th multiple:\n\n");
	
	printf("n = ");
	int n;
	scanf("%d", &n);
	
	printf("\n");
	int i;
	for (i = 1; i <= n; i++) {
		printf("%d", mult3(i));
		if (i != n) {
			printf(",\t");
		}
	}
	
	return 0;
}

int mult3(int n) {
	if (n == 1) {
		return 3;
	}
	return 3 + mult3(n - 1);
}
