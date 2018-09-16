#include <stdio.h>

int main(void) {
	int a, b, c;
	printf("Input 3 numbers: ");
	scanf("%d %d %d", &a, &b, &c);
	
	int mx;
	if (a > b) {
		if (a > c) {
			mx = a;	
		}
		else {
			mx = c;
		}
	}
	else {
		if (b > c) {
			mx = b;
		}
		else {
			mx = c;
		}
	}
	printf("\n%d\n", mx);
	return 0;
}
