#include <stdio.h>
#include <limits.h>

int main(void) {
	//Get n from user
	printf("How many numbers: ");
	int n;
	scanf("%d", &n);
	
	//Exit program if array length is invalid
	if (n < 2) {
		printf("n should be bigger than or equal to 2\n");
		return 0;	
	}
	
	printf("\n"); //For clarity
	
	//Create array
	int numbers[n];
	
	//Get values for array
	int a;
	for (a = 0; a < n; a++) {
		printf("Number %d: ", a+1);
		scanf("%d", &numbers[a]);
	}
		
	//Find largest and second largest
	int first = INT_MIN, second = INT_MIN;
	for (a = 0; a < n; a++) {
		if (first < numbers[a]) {
			second = first;
			first = numbers[a];
		}
		else if ((first > numbers[a]) && (second < numbers[a])) {
			second = numbers[a];	
		}
	}
	
	printf("\nLargest number: %d\nSecond largest number: %d\n", first, second);
	return 0;	
}
