#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define WORD_MAX 16
#define MEANING_MAX 128
#define SYNONYMS_MAX 8

typedef struct _node {
    char word[WORD_MAX], meaning[MEANING_MAX], synonyms[SYNONYMS_MAX][WORD_MAX]; //2D array for synonyms
    int synonyms_count;
    struct _node *next;
} node;

node *head = NULL, *iterator, *pre_iterator; //helpers
char word_buffer[WORD_MAX];
char meaning_buffer[MEANING_MAX];

node *createNode(char *word, char *meaning) {
    node *newNode = malloc(sizeof(node));

    strcpy(newNode -> word, word);
    strcpy(newNode -> meaning, meaning);
    
    newNode -> next = NULL;
    newNode -> synonyms_count = -1;
    
    return newNode;
}

node *findNode(char *word) {
    iterator = head;
    
    while (iterator != NULL) {
        if (strcmp(word, iterator -> word) == 0) return iterator; //found
        iterator = iterator -> next;
    }
    
    return NULL; //not found
}

void showList(void) {
    iterator = head;
    
    printf("\n");
    while (iterator != NULL) {
        printf("%s: %s\n", iterator -> word, iterator -> meaning);
        iterator = iterator -> next;
    }
}

void insertNode(node *newNode) {
    newNode -> next = head;
    head = newNode;
}

void deleteNode(char *word) {
    iterator = head;

    if (strcmp(head -> word, word) == 0) {
        pre_iterator = head;
        head = head -> next;
        free(pre_iterator);
        return;
    }
    else {
        iterator = head -> next, pre_iterator = head;
        while (iterator != NULL) {
            if (strcmp(iterator -> word, word) == 0) {
                pre_iterator -> next = iterator -> next;
                free(iterator);
                return;
            }
            pre_iterator = iterator;
            iterator = iterator -> next;
        }
    }
}


int main(void) {
    int option = 0, synonyms_count = -1;
    node *result = NULL;

    while (true) {
        printf("\nSelect an option:\n");
        printf("\t1. Insert word\n");
        printf("\t2 - Delete word\n");
        printf("\t3 - Check word\n");
        printf("\t4 - Suggest synonyms\n");
        printf("\t5 - Reset\n");
        printf("\t6 - Show all words\n");
        printf("\t7 - Quit\n");
        printf(":");
        scanf("%d", &option);

        switch (option) {
            case 1: //insert
                printf("\nEnter a word: ");
                scanf("\n%s", word_buffer);

                if (findNode(word_buffer) != NULL) {
                    printf("\nERROR! Word is already in the dictionary!\n");
                }
                
                printf("What does '%s' mean: ", word_buffer);
                scanf("\n%[^\n]s", meaning_buffer);

                node *newNode = createNode(word_buffer, meaning_buffer);
                insertNode(newNode);

                printf("How many synonyms does %s has: ", word_buffer);
                scanf("\n%d", &synonyms_count);

                newNode -> synonyms_count = synonyms_count - 1;

                for (int i = 0; i < synonyms_count; i++) {
                    printf("Enter synonym %d: ", i+1);
                    scanf("\n%s", word_buffer);
                    strcpy(newNode -> synonyms[i], word_buffer);
                }

                printf("\n%s (%s) is inserted successfully..\n", word_buffer, meaning_buffer);
                break;
            case 2: //delete
                printf("\nEnter a word: ");
                scanf("\n%s", word_buffer);

                if (findNode(word_buffer) == NULL) {
                    printf("\nERROR! Word is not in the dictionary!\n");
                    break;
                }
                else {
                    deleteNode(word_buffer);
                }
                break;
            case 3: //check
                printf("\nEnter a word: ");
                scanf("\n%s", word_buffer);

                result = findNode(word_buffer);
                if (result != NULL) {
                    printf("\nWord is correct!\n");
                    printf("%s: %s\n", result -> word, result -> meaning);
                }
                else {
                    printf("\nWord is incorrect!\n");
                }
                break;
            case 4: //synonyms
                printf("\nEnter a word: ");
                scanf("\n%s", word_buffer);

                result = findNode(word_buffer);
                if (result != NULL) {
                    if (result -> synonyms_count == -1) printf("\nNo synonyms found for %s\n", result -> word);
                    else {
                        printf("\nSynonyms for %s:\n", result -> word);
                        for (int i = 0; i <= (result -> synonyms_count); i++) {
                            printf("\t%s\n", result -> synonyms[i]);
                        }
                    }
                }
                else {
                    printf("\nWord is incorrect or not found!\n");
                }              
                break;
            case 5: //reset
                iterator = head;
                while (iterator != NULL) {
                    pre_iterator = iterator;
                    iterator = iterator -> next;
                    free(pre_iterator);
                }
                head = NULL;
                break;
            case 6:
                showList();
                break;
            case 7: //exit
                return 0;
            default:
                printf("\nInvalid option..\n");
                break;
        }
    }
}