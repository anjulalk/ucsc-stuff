#include <stdio.h>

int main(void) {
	//Create first array and fill it with values
	int arraySize = 5;
	int array[arraySize];
	
	//Get first array elements from user
	int i;
	for (i = 0; i < arraySize; i++) {
		printf("Number %d: ", i + 1);
		scanf("%d", &array[i]);
	}
	
	//Create an empty secondary array with same size
	int arrayNew[arraySize];
	
	//Copy array items in reverse order
	for (i = 0; i < arraySize; i++) {
		arrayNew[i] = array[(arraySize - 1) - i];	
	}
	
	//Print array elements
	printf("\nFirst array: ");
	for (i = 0; i < arraySize ; i++) {
		printf("%d", array[i]);
		if (i != arraySize - 1) {
			printf(", ");
		}
	}
	printf("\n");
	printf("New array: ");
	for (i = 0; i < arraySize ; i++) {
		printf("%d", arrayNew[i]);
		if (i != arraySize - 1) {
			printf(", ");
		}
	}
	
	return 0;
}
