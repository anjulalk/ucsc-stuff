#include <stdio.h>

int main(void) {
	int n, t, i;
	printf("n = ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("%10d\n", i);
		t += i;
	}
	printf("-----------\n%10d\n", t);
	return 0;
}
