//Seperate lowercase and uppercase characters of a given string
#include <stdio.h>
#include <string.h>
#define MAX 255

int main(void) {
    char string[MAX], letter;
    int i;    
    printf("Enter a string: ");
    scanf("%[^\n]s", string);

    int string_length = strlen(string);

    printf("\nUppercase characters:");
    for (i = 0; i < string_length; i++) {
        char letter = string[i];
        if (letter >= 'A' && letter <= 'Z') {
            printf(" %c", letter);
        }
    }
    
    printf("\nLowercase characters:");
    for (i = 0; i < string_length; i++) {
        char letter = string[i];
        if (letter >= 'a' && letter <= 'z') {
            printf(" %c", letter);
        }
    }
    
    printf("\n");
    return 0;
}
