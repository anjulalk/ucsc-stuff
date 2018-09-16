#include <stdio.h>
#include <math.h>

int main(void) {
	int r;
	
	printf("Radius: ");
	scanf("%d", &r);
	
	printf("Area = %.2f\n", M_PI*r*r);
	
	return 0;
}
