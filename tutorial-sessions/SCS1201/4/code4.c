#include <stdio.h>
#define MAXLEN 256

int main(void) {
	char string[MAXLEN], *char_ptr;
	int length = 0;
	
	printf("Input a string: ");
	scanf("%s[^\n]", &string);
	
	char_ptr = &string[0];
	while (*char_ptr != '\0') {
		length++;
		char_ptr++;
	}
	
	printf("The length of the given string %s is : %i\n", string, length);
	return 0;
}
