#include <stdio.h>

int main(void) {
	//Get n from user
	printf("How many numbers: ");
	int n;
	scanf("%d", &n);
	
	printf("\n"); //Print new line for clarity
	
	//Create array
	int numbers[n];
	
	//Get values for array
	int a;
	for (a = 0; a < n; a++) {
		printf("Number %d: ", a+1);
		scanf("%d", &numbers[a]);
	}
	
	printf("\n");
	
	//Calculate total
	int t = 0;
	for (a = 0; a < n; a++) {
		t += numbers[a];
	}

	//Output mean
	printf("Mean: %f", t / ((float) n));
	return 0;
}
