#include <stdio.h>
#define MAX 10

int main(void) {
	int i;
	
	//input array
	int arr[MAX] = {1, 2, 3, 4, 5}, arr_len = 5;
	
	for (i = 0; i < arr_len; i++) {
		printf("Element: %i\tAddress: %u\n", arr[i], &arr[i]);
	}
	
	return 0;
}
