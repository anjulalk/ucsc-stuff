#include <stdio.h>

int main(void) {
	int average;
	int grades[3];
	
	grades[0] = 80;
	grades[1] = 80;
	grades[2] = 75;
	
	average = (grades[0] + grades[1] + grades[2])/3;
	printf("The average of the 3 grades is: %d", average);
	
	return 0;	
}
