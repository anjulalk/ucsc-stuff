#include <stdio.h>
#define year 2018

int main(void) {
	int byear, age;
	
	printf("Enter your birth year: ");
	scanf("%d", &byear);
	
	age = year - byear;
	printf("You are %d year/s old..", age);
	
	return 0;
}
