#include <stdio.h>

int main(void) {
	int array[] = {1, 2, 3};
	int array_length = 3;
	
	int total = 0;
	
	int i;
	for (i = 0; i < 3; i++) {
		total += array[i];	
	}
	printf("%d\n%.2f", total, (float) total/array_length);
	return 0;
}
