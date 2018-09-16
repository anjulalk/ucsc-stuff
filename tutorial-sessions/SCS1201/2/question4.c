#include <stdio.h>

int main(void) {
	int n;
	int i;
	int ePos=0;
	int oPos=0;
	
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	
	int array[n], oddArray[n], evenArray[n];
	for(i = 0; i < n; i++){
		printf("Element - %d : ", i + 1);
		scanf("%d", &array[i]);
	}
	
	for(i=0; i<n; i++){
		if(array[i]%2==0){
			evenArray[ePos]=array[i];
			ePos++;
		}else{
			oddArray[oPos]=array[i];
			oPos++;
		}
	}
	
	printf("\nThe even elements are :\n");
	for(i=0; i<ePos; i++){
		printf("%d ", evenArray[i]);
	}
	
	printf("\nThe odd elements are :\n");
	for(i=0; i<oPos; i++){
		printf("%d ", oddArray[i]);
	}
	
	return 0;
}
