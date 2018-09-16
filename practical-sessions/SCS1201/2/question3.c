// Check if given string is a palindrome or not
#include <stdio.h>
#include <string.h>
#define MAX 255

void push(int letter);
int pop(void);

int stack[MAX];
int top = -1;

int main(void) {
    char string[MAX], string_reverse[MAX];
    int i;
    
    // Get string from the user
    printf("Input a string: ");
    scanf("%[^\n]s", string);

    int string_size = strlen(string);

    // Push popped values
    for (i = 0; i < string_size; i++) {
        push(string[i]);
    }

    
    for (i = 0; i < string_size; i++) {
        string_reverse[i] = pop();
    }

    printf("Reversed string: %s\n", string_reverse);

    if (strcmp(string, string_reverse) == 0) {
        printf("This string is a palindrome.\n");
    }
    else {
        printf("This string is not a palindrome.\n");
    }

    return 0;
}

void push(int letter) {
    if (top == MAX) {
        printf("Stack overflow");
        return;
    }
    top++;
    stack[top] = letter;
    return;
}

int pop(void) {
    if (top == -1) {
        printf("Stack underflow");
    }
    else {
        top--;
        return stack[top + 1];
    }

}