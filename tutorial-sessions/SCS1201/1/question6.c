#include <stdio.h>
int gcd(int a, int b);

int main(void) {
	int i, j;
	
	printf("1st number: ");
	scanf("%d", &i);
	printf("2nd number: ");
	scanf("%d", &j);
	
	printf("\n\ngcd for %d and %d is: %d", i, j, gcd(i, j)); 
}

int gcd(int a, int b) {
	if (a == b) {
		return a;
	}
	
	if (a > b) {
		return gcd(a - b, b);
	}
	else {
		return gcd(a, b - a);
	}
}
