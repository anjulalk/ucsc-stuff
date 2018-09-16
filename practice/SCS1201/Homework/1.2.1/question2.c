#include <stdio.h>

int main(void) {
	//Get array size from user
	printf("Array size: ");
	int n;
	scanf("%d", &n);
	
	printf("\n");
	
	//Create array
	int array[n];
	
	//Get values for array
	int a;
	for (a = 0; a < n; a++) {
		printf("Element %d: ", a);
		scanf("%d", &array[a]);
	}
	
	//Locate min
	int min = array[0];
	int i;
	for (i = 0; i < 5; i++) {
		if (min > array[i]) {
			min = array[i];
		}
	}
	
	//Locate position of min and print it
	for (i = 0; i < n; i++) {
		if (min == array[i]) {
			printf("\nPosition of the smallest number: %d", i);
		}
	}
	return 0;
}
