#include <stdio.h>
#include <string.h>

#define MAX 20
int stack[MAX];
int top = -1;

int pop() {
  if (top >= 0) {
    return stack[top--];
  } else {
    printf("Stack Under flow");
  }
}

void push(int value) {
  if (top < MAX) {
    stack[++top] = value;
  } else {
    printf("Stack Overflow");
  }
}

int peek() {
  if (top >= 0) {
    return stack[top];
  } else {
    printf("Empty Stack");
  }
}

int main() {
  printf("Enter the phrase: ");
  char phrase[30];
  scanf("%s", &phrase);

  int i;
  for (i = 0;i < strlen(phrase);i++) {
    push(phrase[i]);
  }


  char reversedPhrase[30];
  for (i = 0;i < strlen(phrase);i++) {
    reversedPhrase[i] = pop();
  }
  reversedPhrase[i] = '\0';

  printf("%d\n", strlen(reversedPhrase));
  printf("%d\n", strlen(phrase));

  if (strcmp(reversedPhrase, phrase) == 0) {
    printf("Phalidrome");
  } else {
    printf("No Phalindrome");
  }

  return 0;
}
