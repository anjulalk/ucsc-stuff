#include <stdio.h>
#include <string.h>
#define MAX 100

int queue[MAX];
int front = -1, back = -1;

void enqueue(int value) {
    if (back == MAX - 1) {
        printf("Queue full\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    back++;
    queue[back] = value;
    printf("%d enqueued\n", value);
    return;
}

int dequeue(void) {
    if (front == -1) {
        printf("\nQueue empty\n");
        return -1;
    }

    int value = queue[front];
    front++;
    
    if (front > back) {
        front = back = -1;
        //special case to reset queue if it's empty so it's full space can be reused
    }

    printf("%d dequeued\n", value);
    return value;
}

void display(void) {
    if (front == -1 || front > back) {
        printf("Queue empty\n");
        return;
    }

    int i;
    for (i = front; i <= back; i++) {
        printf("%d", queue[i]);
        if (i != back) {
            printf(", ");
        }
    }
    printf("\n");
}

void sort(void) {
    if ((front == -1) || (front > back)) {
        printf("\nQueue empty\n");
        return;
    }

    int size = back - front + 1;

    int i, j;
    for (i = 0; i < size; i++) {
        int x = dequeue();
        for (j = 0; j < size - 1; j++) {
            int y = dequeue();
            if (x > y) {
                printf("%d is bigger than %d\n", x, y);
                enqueue(y);
            }
            else {
                printf("%d is smaller than %d\n", x, y);
                enqueue(x);
                x = y;
            } 
            printf("\n");
        }
        
    enqueue(x);
    }
}

int main(void) {
    printf("\nEnqueueing values..\n");
    enqueue(40);
    enqueue(50);
    enqueue(20);
    enqueue(60);
    enqueue(10);

    printf("\nBefore sorting: ");
    display();

    printf("\nSorting..\n\n");
    sort();

    printf("\nOutput: ");
    display();

    return 0;
}