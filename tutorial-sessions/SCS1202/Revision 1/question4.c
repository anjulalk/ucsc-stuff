#include <stdio.h>
#include <math.h>

int main(void) {
	int r;
	
	printf("Radius: ");
	scanf("%d", &r);
	
	printf("\nSphere surface area = %.2f\n", 4*M_PI*r*r);
	printf("Sphere volume = %.2f\n", (4*M_PI*r*r*r)/3);
	
	return 0;
}
