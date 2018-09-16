#include <stdio.h>
#include <stdbool.h>

bool isChecked(int n, int *array){
	int k;
    for (k = 0; k < 12; k++) {
        if (array[k] == n)
            return true;
    }
    return false;
}

int main(void) {
	int array[12] = {6, 1, 2, 4, 4, 4, 6, 1, 2, 3, 3};
	int checkedArray[12];
	int check = 0, count = 0, i, j, k, checkedArrPosition=0;
	
	for(i = 0; i < 12;i++){
		count += array[i];
	}
	printf("Mean = %.2f\n", count / 11.0);
	
	count = 0;
	for(i = 0; i < 12; i++){
		if (!isChecked(array[i], checkedArray)) { 
			check = array[i];
			checkedArray[checkedArrPosition] = check;
			for (j = 0; j < 12; j++){
				if(check == array[j]){
					count++;
				}
			}
			printf("Number %d  is repeated %d times\n", check, count);
			count = 0;
			checkedArrPosition++;	
		}
	} 
	
	return 0;
}
