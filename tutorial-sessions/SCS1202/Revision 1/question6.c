#include <stdio.h>

int main(void) {
	int begin, end;
	printf("Input range (begin,end): ");
	scanf("%d,%d", &begin, &end);
	
	if (begin >= end) {
		printf("Error!\n");
		return 1;
	}
	
	int i, j;
	for (i = begin; i <= end; i++) {
		if (isprime(i)) {
			printf("%d\n", i);
		};
	}
	
	return 0;
}

int isprime(int num) {
	int i;
    if (num <= 1) 
		return 0;
    if (num % 2 == 0 && num > 2) return 0;
    for(i = 3; i < num / 2; i++) {
         if (num % i == 0)
             return 0;
    }
    return 1;
}
