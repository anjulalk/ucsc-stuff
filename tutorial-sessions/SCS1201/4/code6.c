#include <stdio.h>
#define MAX 10

int main(void) {
	int tot = 0, i;
	
	//input array
	int arr[MAX] = {1, 2, 3, 4, 5, 6}, arr_len = 6;

	for (i = 0; i < arr_len; i++) {
		tot += *(&arr[i]); 
		//tot += *(arr + i); 
	}
	
	printf("%i\n", tot);
	return 0;
}
