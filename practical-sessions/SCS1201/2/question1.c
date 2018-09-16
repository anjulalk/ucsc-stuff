// Stack implementation
#include <stdio.h>
#define MAX 10

// Function prototypes
int is_empty(void);
int is_full(void);
int push(int value);
int pop(void);
void output(void);
int peek(void);
int get_size(void);

void instruct(void);
void line(void);

// Initiation
int stack[MAX], top = -1;
int option = 0, value;

int main(void) {
	do {
		// Prompt user for options
		instruct();
		scanf("%d", &option);
		
		if (option == 1) {
			printf("Enter item to push: ");
			scanf("%d", &value);
			if (push(value)) {
				printf("Stack overflow");
			}
		}
		else if (option == 2) {
			if (pop()) {
				printf("Stack underflow");
			}
		}
		else if (option == 3) {
			if (is_empty()) {
				printf("Stack is empty");
			}
			else {
				printf("Stack is not empty");
			}
		}
		else if (option == 4) {
			if (is_full()) {
				printf("Stack is full");
			}
			else {
				printf("Stack is not full");
			}
		}
		else if (option == 5) {
			int size = get_size();
			if (size == -1) {
				printf("Stack is empty");
			}
			else {
				printf("Size: %d", size);
			}
		}
		else if (option == 6) {
			output();
		}
		else if (option == 7) {
			int top_val = peek();
			if (top == -1) {
				printf("Stack is empty");
			}
			else {
				printf("Top value: %d", top_val);
			}
		}
		else if (option == 8) {
			return 0;
		}
		else {
			printf("Invalid option.");
		}
		line();
	} while (option != 8);
	
	return 1;
}

int is_empty(void) {
	if (top == -1) {
		return 0;
	}
	return 1;
}

int is_full(void) {
	if (top == MAX - 1) {
		return 0;
	}
	return 1;
}

int push(int value) {
	if (top == MAX - 1) {
		return 1;
	}
	top++;
	stack[top] = value;
	
	printf("Value %d was pushed to position %d.", value, top);
	return 0;
}

int pop(void) {
	if (top == -1) {
		return 1;
	}

	printf("Value %d was popped from position %d", stack[top], top);
	top--;
	return 0;
}

void output(void) {
	int i;
	
	if (top == -1) {
		printf("Stack is empty");
	}
	else {
		printf("Stack: ");
		for (i = 0; i <= top; i++) {
			printf("%d", stack[i]);
			if (i != top) {
				printf(", ");
			}
		}
	}
}

int peek(void) {
	return stack[top];
}


int get_size(void) {
	return top;
}

// Other functions
void instruct(void) {
	printf("Select an option:\n\t1. Push item to the top\n\t2. Pop item from the top\n\t3. Check if stack is empty\n\t4. Check if stack is full\n\t5. Get size of the stack\n\t6. Print the elements of the stack\n\t7. Peek the stack\n\t8. Exit\n\n: ");
}

void line(void) {
	int i;
	printf("\n");
	for (i = 0; i < 60; i++) {
		printf("-");
	}
	printf("\n");
}