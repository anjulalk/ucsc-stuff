#include <stdio.h>

int main(void) {
	//Get the number of digits from user
	int n;
	printf("How many digits?\nn = ");
	scanf("%d", &n);
	
	//Exit if number is 0 or negative
	if (n < 1) {
		printf("Invalid number\n");
		return 1;	
	}
	
	//Create array to store digits
	int num[n];
	
	//Get digits from user
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("Digit %d: ", i + 1);
		scanf("%d", &j);
		if (j < 0) {
			printf("Invalid digit\n");
			return 2;
		}
		else {
			num[i] = j;	
		}
	}
	
	//Print the numbers of array
	printf("\nNumber: ");
	for (i = 0; i < n; i++) {
		printf("%d", num[i]);
	}
	printf("\n");
	return 0;
}
