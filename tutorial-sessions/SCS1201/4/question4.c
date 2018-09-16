#include <stdio.h>         
#include <stdlib.h>

#define MAX 128 

int front = -1, rear = -1, count = 0;
int n, m;
int queue[MAX];          

int enqueue(int value); //returns 1 if queue is full, otherwise 0
int dequeue(void); //return -1 is queue is empty, otherwise dequeued item is returned
void display(void); //displays all elements of the queue

int main(void) {
    printf("\nEnter n and m: ");
    scanf("%d %d", &n, &m); //n is how many men, m is how many skipped
    
    if (n < 1 || m < 1) {
        printf("Invalid input\n");
        return 1;
    }

    //populate queue with elements from 1 to n
    int i;
    for (i = 1; i <= n; i++) {
        enqueue(i);
    }
    display();

    int j, k;
    //repeat until one element remains
    while (count != 1) {
        //enqueue and dequeue elements until m^th element is met
        //this is only to traverse the queue
        for (j = 0; j < m - 1; j++) {
            k = dequeue();
            //printf("%d dequeued\n", k);

            enqueue(k);
            //printf("%d enqueued\n", k);
        }

        //at this point the m^th element is located
        //dequeue the m^th element
        k = dequeue();
        printf("%d was killed\n", k);
    }
    //at this point only one item remains
    //and that is the one who's spared
    int josephus = dequeue();
    printf("\n%d is spared\n", josephus);

    return 0;
}

int enqueue(int value) {
    if ((front == 0 && rear == n - 1) || front == rear + 1) {
        return 1;
    }

    if (front == -1) {
        front++;
    }

    if (rear == n - 1) {
        rear = 0;
    }
    else {
        rear = rear + 1;
    }

    queue[rear] = value;
    count++;
    return 0;
}

int dequeue(void) {
    int value;

    if (front == -1)
    {
        return -1;
    }

    value = queue[front];

    if (front == n - 1)
        front = 0;
    else if (front == rear)
    {
        front = -1, rear = -1;
    }
    else {
        front += 1;
    }

    count--;
    return value;
}

void display(void) {
    int i;
    if (front == -1)
    {
        printf("Queue empty\n");
        return;
    }

    printf("\n");
    i = front;
    if (front <= rear)
    {
        while(i <= rear)
            printf("%d ", queue[i++]);
        printf("\n");
    }
    else {
        while (i <= n-1) {
           printf("%d ", queue[i++]);
        }

        i = 0;
        while(i <= rear) {
            printf("%d ", queue[i++]);
        }
        printf("\n");
    }
    printf("\n");
}
