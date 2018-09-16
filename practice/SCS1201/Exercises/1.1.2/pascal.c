#include <stdio.h>

int main(void) {
	int n, i;
	printf("Pascal triangle upto n^th line\nn = ");
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++) {
		pascal(i);
		printf("\n");
	}
}

int pascal(int i) {
	if (i == 1) {
		print("%d ", 1);
	}
	else if (i == 2) {
		printf("%d %d ", 1, 1);
	}
	else {
		printf("%d ", 1);
		int k;
		for (k = 1; k <= i; k++) {
			pascal_helper(k);
		}
		for (k = 1; k <= i; k++) {
			pascal_helper(k);
		}
		printf("%d ", 1);
	}
}

int pascal_helper(int j) {
	
}
