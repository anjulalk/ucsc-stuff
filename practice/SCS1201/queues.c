#include <stdio.h>
#define MAX 10

//initialization
int queue[MAX], front = -1, back = -1, item;
int option = 0;

//function prototypes
int show(void);
int enqueue(int item);
int dequeue(void);

int main(void) {
    do {
        printf("Enter an option,\n\t1. Show queue\n\t2. Enqueue item\n\t3. Dequeue item\n\t4. Quit\n:");
        scanf("%d", &option);
        
        if (option == 1) {
            show();       
        }
        else if (option == 2) {
            printf("Enter an item: ");
            scanf("%d", &item);
            enqueue(item);
        }
        else if (option == 3) {
            dequeue();
        }
        else if (option == 4) {
            printf("Quiting...");
            return 0;
        }
        else {
            printf("Invalid option.");
        }
        printf("\n--------------------------------------\n");
    } while (option != 4);

    return 0;
}


int show(void) {
    int i = 0;
    if ((front > back) || (front == -1)) {
        printf("Queue is empty.");
        return 1;
    }
    else {
        printf("Queue: ");
        for (i = front; i <= back; i++) {
            printf("%d", queue[i]);
            if (i != back) {
                printf(", ");
            }
        }
        return 0;
    }
}

int enqueue(int item) {
    if (back == MAX -1) {
        printf("Queue overflow.");
        return 1;
    }

    if (front == -1)  {
        //means that the queue is uninitialized
        front = 0; 
    }

    back++;
    queue[back] = item;
    return 0;
}

int dequeue(void) {
    if ((front > back) && (front == -1)) {
        printf("Queue is empty.");
        return 1;
    } 
    front++;
    return 0;
}