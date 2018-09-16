#include <stdio.h>

#define MAX 20
int stack[MAX];
int top = -1;

int pop() {
  if (top >= 0) {
    return stack[top--];
  }
  else {
    printf("Stack Underflow");
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
	printf("Enter number <20: ");
	int n;
  scanf("%d", &n);
  int array[n];

  int i;
  	for (i = 0;i < n;i++) {
    	printf("Enter element %d : ", i);
    scanf("%d", &array[i]);
  }

  printf("Elements: ");
  for (i = 0;i < n;i++) {
    printf("%d ", array[i]);
  }

  for (i = 0;i < n;i++) {
    push(array[i]);
  }

  for (i = 0;i < n;i++) {
    array[i] = pop();
  }

  printf("\nRevised Elements: ");
  for (i = 0;i < n;i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}
