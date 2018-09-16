#include <stdio.h>
#include <string.h>
#define MAX 10
#define MAXLEN 64

char queue[MAX][MAXLEN];
int front = -1, back = -1, count = 0;

void enqueue(char *name) {
    if (back == MAX - 1) {
        printf("Queue full\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    back++;
    count++;
    strcpy(queue[back], name);
    printf("%s enqueued\n", name);
    return;
}

void dequeue(void) {
    if (front == -1) {
        printf("Queue is empty");
        return;
    }

    printf("%s dequeued\n", queue[front]);
    front++;
    
    if (front > back) {
        front = back = -1;
    }
    count--;
    return;
}

void display(void) {
    if (front == -1 || front > back) {
        printf("Queue empty\n");
        return;
    }

    int i;
    for (i = front; i <= back; i++) {
        printf("%s", queue[i]);
        if (i != back) {
            printf(",\t");
        }
    }
}

int main(void) {
    enqueue("John");
	enqueue("Kate");
	enqueue("Shankar");
	dequeue();
	enqueue("Zara");
	enqueue("Jack");
	dequeue();
	dequeue();
	printf("%d patients are waiting for doctor!\n", count);
    
    return 0;
}