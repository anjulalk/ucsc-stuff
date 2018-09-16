#include <stdio.h>

int main(void) {
    /* Create 2D array to store data
    grades[0] for Mathematics, grades[1] for Physics */

   // Sample data
   int grades[2][5] = {
        {45, 67, 86, 45, 34},
        {65, 34, 64, 62, 94}
        };

    // Calculate the average of two subjects
    int i;
	for (i = 0; i < 2; i++) {
        int total = 0;
        float average = 0;
        int j;
		for (j = 0; j < 5; j++) {
            // Add each mark to total
            total += grades[i][j];
        } 
        // Calculate average
        average = total / 5.0;
        
        // Print average along with subject name
        if (i == 0) {
        	printf("Maths: %.2f\n", average);	
    	}
    	else {
    		printf("Physics: %.2f\n", average);	
    	}
    }
}
