#include <stdio.h>

int main(void) {
	int myArray[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};
	
	printf("%d", myArray[1][2]);
	return 0;
}
