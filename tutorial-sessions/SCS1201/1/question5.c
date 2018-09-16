#include <stdio.h>
void pattern(int m);

int main(void) {
	//Get n from user
	printf("n = ");
	int n;
	scanf("%d", &n);
	
	//Check if n is positive, return otherwise
	if (n < 1) {
		printf("Error: n expected to be positive");
		return 1;
	}
	
	//Call function
	pattern(n);
}

void pattern(int m) {
	if (m == 1) {
		printf("%d", 1);
		return;
	}
	
	pattern(m - 1);
	printf("%d", m);
	pattern(m - 1);
}
