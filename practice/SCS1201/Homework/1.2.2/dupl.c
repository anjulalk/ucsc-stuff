#include <stdio.h>
#include <stdbool.h>

int main(void) {
	//Initiate variables
	int i, j, k, l, m, repeat_count;
	bool is_checked = false;

	//Get length of array
	printf("Array length: ");
	scanf("%d", &i);
	
	//Validate length
	if (i < 1) {
		printf("\nInvalid length\n");
		return 1;	
	}
	
	//Create arrays
	int num_array[i];
	int checked[i];
	int checked_pos = 0;
	
	//Fill array with user input
	printf("\n");
	for (j = 0; j < i; j++) {
		printf("Number %d: ", j + 1);
		scanf("%d", &num_array[j]);
	}
	
	printf("\n");
	
	for (k = 0; k < i; k++) {
		is_checked = false;
		//Check if item exists in checked array
		for (m = 0; m < checked_pos; m++) {
			if (checked[m] ==	num_array[k]) {
				is_checked = true;
			}
		}
		//Workaround for continue loop
		if (is_checked) {
			break;	
		}
		//Reset repeat_count
		repeat_count = 0;
		//Check other elements with k^th element for repeated elements
		for (l = k; l < i; l++) {
			if (num_array[k] == num_array[l]) {
				repeat_count++;
			}
		}
		//Print result
		if (repeat_count > 1) {
			printf("Number %d is repeated %d times\n", num_array[k], repeat_count);	
		}
		//Add item to checked array
		checked[checked_pos] = num_array[k];
		checked_pos++;
	}
}
