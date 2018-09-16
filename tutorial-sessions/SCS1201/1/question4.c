#include <stdio.h>
long sumof(int j);

int main(void) {
	//Get input
	printf("Sum of natural numbers up to: ");
	int i;
	scanf("%d", &i);
	
	//Call sumof function and dispay returned value
	printf("%d\n", sumof(i));	
}

long sumof(int j) {
	//Base case
	if (j == 1) {
		return 1;
	}
	return (j + sumof(j - 1));	
}
