#include <stdio.h>

int main(void) {
	//Initiate value
	int i;
	//Get Fibonacci until:
	printf("Fibonacci series for: ");
	scanf("%d", &i);
	
	//Check if number is positive
	if (i < 1) {
		printf("Error: Positive number required!\n");
		return 1;	
	}
	
	//Print the series upto i
	int j;
	for (j = 1; j <= i; j++) {
		printf("%d\n", fib(j));
	}

	return 0;
}

//Define function for n^th fibonacci number
int fib(int n) {
	//Base cases
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		return 1;
	}
	
	//Call the function itself
	return fib(n - 1) + fib(n - 2);
	
}
