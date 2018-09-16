#include <stdio.h>

int main(void) {
	printf("Input Year: ");
	
	int year;
	scanf("%d", &year);
	
	if (year % 4 == 0) {
		printf("Leap year..\n");
		return 0;
	}
	printf("Not a leap year...\n");
	return 0;
}
