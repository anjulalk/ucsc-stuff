//Contains all definitions and prototypes for the program
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "question1_block.h"

//Definitions
#define TOTAL_MEMORY 2560
#define OS_MEMORY 400

//Function prototypes
int initiate(void);
int allocate(int process_id, int size);
int terminate(int process_id);
void memstate(void);
void memstate_detailed(void);
