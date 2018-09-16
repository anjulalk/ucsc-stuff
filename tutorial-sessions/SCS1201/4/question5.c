#include <stdio.h>         
#include <stdlib.h>
#include <string.h>
#define QUEUE_MAX 32 
#define WORD_MAXLEN 32
#define STRING_MAXLEN 256

int front = -1, rear = -1, count = 0;
char *queue[QUEUE_MAX];          

int enqueue(char *string); 
char *dequeue(void);
void display(void);

int main(void) {
    //input string
    printf("Input string: ");
    char string[STRING_MAXLEN];
    scanf("%[^\n]s", string);
    int string_len = strlen(string);
    
    //input k
    int k;
    printf("k = ");
    scanf("%d", &k);

    int i, j = 0;
    //create a temporary word
    char *word = malloc(sizeof(char) * WORD_MAXLEN);
    //iterate over each letter of string 
    //store them in word until an space or \n is found
    for (i = 0; i <= string_len; i++) {
        if ((string[i] == ' ') || (string[i] == '\0')) {
            //if space or end of string is found, enqueue that word
            enqueue(word);
            //reallocate another array for new word
            word = malloc(sizeof(char) * WORD_MAXLEN);
            j = 0;
        }
        else {
            word[j] = string[i];
            j++;
        }
    }
    //all words are queued successfully

    //dequeue and enqueue count-k times
    int l;
    for (l = 0; l < count - k; l++) {
        enqueue(dequeue());
    }

    //print last value
    //or kth from the end in other words
    printf("Output: %s\n", dequeue());

    return 0;
}

int enqueue(char *string) {
    if ((front == 0 && rear == QUEUE_MAX - 1) || front == rear + 1) {
        return 1;
    }

    if (front == -1) {
        front++;
    }

    if (rear == QUEUE_MAX - 1) {
        rear = 0;
    }
    else {
        rear = rear + 1;
    }

    queue[rear] = string;
    count++;
    return 0;
}

char *dequeue(void) {
    char *word;

    if (front == -1)
    {
        return NULL;
    }

    word = queue[front];

    if (front == QUEUE_MAX - 1)
        front = 0;
    else if (front == rear)
    {
        front = -1, rear = -1;
    }
    else {
        front += 1;
    }

    count--;
    return word;
}

void display(void) {
    int i;
    if (front == -1)
    {
        printf("Queue empty\n");
        return;
    }

    i = front;
    if (front <= rear)
    {
        while(i <= rear)
            printf("%s ", queue[i++]);
        printf("\n");
    }
    else {
        while (i <= QUEUE_MAX - 1) {
           printf("%s ", queue[i++]);
        }

        i = 0;
        while(i <= rear) {
            printf("%s ", queue[i++]);
        }
        printf("\n");
    }
}
