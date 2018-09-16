#include <stdio.h>

int main(void) {
	int numbers[10];
	
	//Populate the array
	numbers[0] = 10;
	numbers[1] = 20;
	numbers[2] = 30;
	numbers[3] = 40;
	numbers[4] = 50;
	numbers[5] = 60;
	numbers[6] = 70;
	
	//Print the 7th number of the array
	printf("The 7th number in the array is %d", numbers[6]);
	return 0;
}
