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
    //printf("Success!\n");
    return;
}

int dequeue(void) {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = queue[front];
    front++;
    
    if (front > back) {
        front = back = -1;
        //special case to reset queue if it's empty so it's full space can be reused
    }

    //printf("Success!\n");
    return value;
}

void display(void) {
    if (front == -1 || front > back) {
        printf("Queue empty\n");
        return;
    }

    int i;
    for (i = front; i <= back; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void sort(void) {
    if ((front == -1) || (front > back)) {
        printf("Queue empty\n");
        return;
    }

    int size = back - front + 1;

    int i, j;
    for (i = 0; i < size; i++) {
        int x = dequeue();
        for (j = 0; j < size - 1; j++) {
            int y = dequeue();
            if (x < y) {
                enqueue(y);
            }
            else {
                enqueue(x);
                x = y;
            } 
        }
    enqueue(x);
    }
}

int main(void) {
    printf("Input an negative number to stop..\n");
    printf("Enter values: \n");
    
    int value = 0;

    scanf("%d", &value);
    do {
        enqueue(value);
        scanf("%d", &value);
    } while (value >= 0);

    sort();

    printf("\n");
    display();
    return 0;
}