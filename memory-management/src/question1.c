 // Question 01
// First-fit algorithm implementation in C using linked lists

#include "question1_header.h" // Includes all the header files, definitions and prototypes

block *start = NULL; // Start point of the memory block linked list

// Respoinsible for handling user i/o and providing a UI
int main(void) {
    int process_id, size, option = 0;
    
    // Allocate memory for the start block and configure it
    initiate();

    // Allocate 400k to the OS
    allocate(0, OS_MEMORY);

    // Start the user interface
    while (true) {
        printf("\n#######################################\n");
        printf("########## MEMORY MANAGEMENT ##########\n");
        printf("#######################################\n");
        
        printf("\nSelect an option:\n");
        printf("\t 1. Allocate memory\n");
        printf("\t 2. Terminate process\n");
        printf("\t 3. View memory state\n");
        printf("\t 4. View memory state (detailed) \n");
        printf("\t 0. Exit\n");
        printf(":");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nProcess ID: ");
                scanf("%d[^\n]", &process_id);

                printf("Memory size: ");
                scanf("%d[^\n]", &size);
                
                if (allocate(process_id, size) == 0) {
                    printf("\nMemory block of %dk was allocated for P%d\n\n", size, process_id);
                }
                else {
                    printf("\nNot enough memory!\n\n");
                }
                break;
            case 2:
                printf("\nProcess ID: ");
                scanf("%d[^\n]", &process_id);

                if (process_id <= 0) {
                    // PID 0 is dedicated to OS
                    printf("\nInvalid PID!\n");
                    break;
                }

                if (terminate(process_id) == 0) {
                    printf("\nProcess P%d was terminated. Memory block was freed\n\n", process_id);
                }
                else {
                    printf("\nPID not found!\n");
                }
                break;
            case 3:
                memstate();
                break;
            case 4:
                memstate_detailed();
                break;
            case 0:
                printf("\nHave a nice day!\n\n");
                return 0;
            default:
                printf("\n\nPlease try again..\n");   
        }
    }

}

// Allocate memory for the first block and configure it according to our needs
int initiate(void) {
    // Allocate memory for first block
    start = malloc(sizeof(block));

	// Configure the memory block
    start -> begin_address = 0;
    start -> end_address = TOTAL_MEMORY;
    start -> size = TOTAL_MEMORY;
    start -> hole = true;
    start -> process_id = -1;
    start -> next = NULL; // This is only temporary
      

    return 0;
}

int allocate(int process_id, int size) {
    // Assign temporary pointer the value of start
    block *pointer = start;

    // Traverse until a free block with enough size is found
    while (pointer != NULL) {
        if ((pointer -> hole) == true) {
        	// Check if the current block is free
            if (pointer -> size == size) {
                // And the perfect block is found!
                // Use it for the process
                pointer -> hole = false;
                pointer -> process_id = process_id;
                
                return 0;
            }
            else if ((pointer -> size) > size) {
                // A suitable block is found

                // Temporary store pointer -> end_address and pointer -> next for later retrieval
                int _end_address = pointer -> end_address;
				block *_next = pointer -> next;

                // Minimize the currently pointed block to required size and use it for the process
                pointer -> size = size;
                pointer -> hole = false;
                pointer -> process_id = process_id;
                pointer -> end_address = pointer -> begin_address + size;
                
				// Create new block for the rest of free space
                block *new_block = malloc(sizeof(block));

                // Use it for the rest of free memory space
                pointer -> next = new_block;
                
                new_block -> begin_address = pointer -> end_address;
                new_block -> end_address = _end_address; // Old end_address of the block we've minimized
                new_block -> size = (new_block -> end_address) - (new_block -> begin_address);
                new_block -> hole = true;
                new_block -> process_id = -1;
				new_block -> next = _next; // Old next address of the block we've minimized

                return 0; // Returns if the process was successful
            }

        }
		
		// Traverse further if not found
        pointer = pointer -> next;
    }
	
	// Not enough memory for allocation
    return 1;
}

int terminate(int process_id) {
    block *pointer = start, *matching_block = NULL, *pre_block, *post_block, *free_block;

    // Find if the block with matching PID exist
    while (pointer != NULL) {
        if (pointer -> process_id == process_id) {
            // Assign the pointer to that block to maching_block
            matching_block = pointer;
            break;
        }
        // pre_ptr pointed to the previous block
        pre_block = pointer;
        
        // Traverse further
		pointer = pointer -> next;
    }

    // If not then exit
    if (matching_block == NULL) {
        printf("\nPID doesn't match!\n");
        return 1;
    }
    
    // Now pre_block is pointed to the block before matching_block

    // Check if pre_block free or occupied
    if (pre_block -> hole == true) {
        // It's free! 
        // Expand pre_block over matching_block
        pre_block -> end_address = matching_block -> end_address;
        pre_block -> size += matching_block -> size;
        pre_block -> next = matching_block -> next;

		// Free memory used by the matching_block block
        free(matching_block);

        // Store the address of the current block which we've freed for later
        free_block = pre_block;
    }
    else {
        // It's occupied!
        
        // There's no free block to expand on the previous position
        // Mark matching_block as free
        matching_block -> hole = true;
        matching_block -> process_id = -1;

         // Store the address of the current block which we've freed for later
        free_block = matching_block;
    }
    
	//////////
    // Now free_block is pointed at the address of previously freed block
    if (free_block -> next != NULL) {
        // A block after the currently freed block free_block exits!
        post_block = free_block -> next; // Store it as post_block

        // If the post_block is free, then we need to join it with the free_block
        if (post_block -> hole == true) {
            // post_block is a free memory block
            // Maximize the free_block over post_block
            free_block -> end_address = post_block -> end_address;
            free_block -> size += post_block -> size;
            free_block -> next = post_block -> next;
            
            // Free memory of the post_block
            free(post_block);
        }

		// Process successful
        return 0;
    }

}

void memstate(void) {
    // Tempory pointer for traversing
    block *pointer = start, *_pointer;

    printf("\n");

    do {
        printf("%4dk - - - - - - \n\n", pointer-> begin_address);

        if (pointer -> process_id == -1) {
            printf("        FREE\n\n");
        }
        else {
            if (pointer -> process_id == 0) {
                printf("         OS\n\n");
            }
            else {
                printf("         P%d\n\n", pointer -> process_id);
            }
        }

		// Pointed to the previous pointer
        _pointer = pointer;
        // Traverse
        pointer = pointer -> next;
        
    } while (pointer != NULL);

    printf("%4dk - - - - - - \n", _pointer -> end_address);    
}

void memstate_detailed(void) {
    // Tempory pointer for traversing
    block *pointer = start;
    
    // block count
	int count = 0;
    
    printf("\n");
    
    do {
        printf("****** BLOCK #%d ******\n", count);
        printf("Begin: %d\n", pointer -> begin_address);
        printf("End: %d\n", pointer -> end_address);
        printf("Size: %d\n", pointer -> size);
        printf("Hole: %s\n", pointer -> hole ? "true" : "false");
        printf("PID: %d\n\n", pointer -> process_id);
        
        pointer = pointer -> next;
        count++;
    } while (pointer != NULL);    
}

