#include <stdio.h>
#include <math.h>
#define DIGIT_LIM 10

int main(void) {
	int num, sum, digits[DIGIT_LIM];
	
	printf("Enter a number: ");
	scanf("%d", &num);

	int i, _num = num;
	for (i = 0; i < DIGIT_LIM; i++) {
		digits[i] = _num % 10;
		_num = _num / 10;
	}

	for (i = 0; i < DIGIT_LIM; i++) {
		sum += pow(digits[i], 3);
	}

	if (sum == num) {
		printf("%d is an Armstrong number\n\n", num);
	}
	else {
		printf("%d is not an Armstrong number\n\n", num);
	}

	return 0;
}