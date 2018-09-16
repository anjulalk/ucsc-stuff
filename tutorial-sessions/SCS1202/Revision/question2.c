#include <stdio.h>

int main(void) {
	int a = 1, b = -3, c = -2;
	
	printf("x^2 - 3x - 2 = 0\n");
	printf("b^2 - 4ac = %f\n", ((float) (b^2 - 4*a*c)));
	
	return 0;
}
