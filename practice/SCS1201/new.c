#include <stdio.h>
#define MAX 100

void enqueue(void);
void dequeue(void);
void display(void);

int front = -1, rear = -1, option;
char name[MAX][MAX], val;



void enqueue() {
	printf("Enter the name of the paitent : ");    	
	if (rear == MAX - 1)
		printf("Line is full");
	else if (front == -1 && rear == -1)
		front = rear = 0;
	else
		rear++;
	 	//printf("%d",rear);
      	scanf("%s", &name[rear][0]);	
}

void dequeue(void){
	if (front == -1 || front > rear )
		printf("Line is empty");
	else
	{
		front++;
		if (front > rear)
			front = rear = -1;
	}
}

void display(void)	{
	int i;
	if (front==-1 || front >rear)
		printf("The queue is empty");
	else
	{
		for(i = front; i <= rear; i++){
			printf("%s\t", name[i]);
            if (name[i] == &name[i][0]) {
                printf("You are correct.");
            }
		}
	}
}

int main (void) {
		printf("\n\n*******Medical Cneter********");
		printf("\n\t1. Insert a paitent");
		printf("\n\t2. Remove a paitent");
		printf("\n\t3. Check Paitent list");
		printf("\n\t4. Display");
		printf("\n\t5. Exit");
	do {
		printf("\nEnter your option: ");
		scanf("%d", &option);
		switch (option) {	
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			//case 3:
			//val=peek();
			//if(val!=-1)
			//	printf("The Frist element in the queue  is:%d",val);
			//break;
			case 4:
				display();
				break;
		}	
	} while(option !=5);
}
