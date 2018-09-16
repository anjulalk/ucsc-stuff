// Question 02
// The Sleeping Barber implementation in C

// Contains all headers
#include "question2_header.h"

// Initiate variables
int n, m, customer_count = 1;
bool barber_sleeping = true;

// Creates pointer variable for wait_queue
queue *wait_queue;

int main(void) {
	//Allocate memory for wait_queue and assign the address to pointer wait_queue
    wait_queue = malloc(sizeof(queue));

	// Get the number of chairs in the waiting room
    int option;
    printf("Number of waiting seats in the barbershop: ");
    scanf("%d", &m);
    
    // Total number of chairs including the hot seat
	n = m + 1; // m = n - 1
	printf("Barbershop has total of %d chairs including barberroom\n", n);
	
	// Config wait_queue
    wait_queue -> front = 0;
    wait_queue -> back = 0;
    wait_queue -> count = 0;
    wait_queue -> capacity = n;
    wait_queue -> array = malloc((n) * sizeof(int));

    printf("\n#############################\n");
    printf("######## BARBERSHOP #########\n");
    printf("#############################\n\n");

    while (option != 3) {
    	// Print the current status of the barber
        if (barber_sleeping == true) {
            printf("The barber is sleeping..\n");
        }

		// Print the current status of the barbershop
        
		// If queue is empty, barbershop is empty 
        if (wait_queue -> count == 0) {
            printf("Barbershop is empty..\n");
        }
        else { // Means that queue is not empty 
            // The front of wait_queue is the customer whose hair is being cut
            if ((wait_queue -> array)[wait_queue -> front] > 0) {
                printf("Barber is cutting hair of # %d customer.", wait_queue -> array[wait_queue -> front]);
            }
            
            // Print the status of waiting queue
            if (wait_queue -> count > 0) {
                printf("\n%d people waiting in the room..", wait_queue -> count - 1);
                printf("\n%d chairs left..\n\n", wait_queue -> capacity - wait_queue -> count);
            }
        }

        printf("\n#############################\n\nSelect an option:\n");
        printf("\t1. New customer arrives\n");
        printf("\t2. Current customer leaves\n");
        printf("\t3. Exit\n");
        printf(": ");
        
        scanf("%d", &option);

        switch (option) {
            case 1:
                customer_arrive();
                break;
            case 2:
                customer_leave();
                break;
            case 3:
                printf("\nGood bye! Have a nice day!\n\n");
                return 0;
            default:
                printf("\nTry again!\n\n");
                break;
        }
    }
}

int enqueue(int element) {
	// Queue is full
    if (wait_queue -> count == wait_queue -> capacity) {
        return -1;
    }
	
	// Add element to the back of the queue
    (wait_queue -> array)[wait_queue -> back] = element;

	// Increment customer_count
    customer_count++;
    
    // Increment wait_queue count
    wait_queue -> count++;
    
    // Increment wait_queue back
    wait_queue -> back = (wait_queue -> back + 1) % (wait_queue -> capacity);
    
	// Success!
	return 0;
}

int dequeue() {
    if (wait_queue -> count == 0) {
        // Nothing to dequeue
		return -1;
    }
    
    // Temporary store dequeued element for returning later
    int dequeued_elem = (wait_queue -> array)[wait_queue -> front];
    
    // Decrement count
    wait_queue -> count--;
    
    // Increment front
    wait_queue -> front = (wait_queue -> front + 1) % (wait_queue -> capacity);

	return dequeued_elem;
}

int customer_arrive() {
    printf("\nNew client arrives at the barbershop..\n");
    
    // Enqueues the customer
    if (enqueue(customer_count) != 0) {
    	// Queue full
        printf("House full! Customer has no chair to sit so he leaves the barbershop!\n\n");
        return 1;
    }

    if (barber_sleeping == true) {
    	// We need to wake up the barber
        barber_sleeping = false;
        printf("Client wakes up the sleeping barber..\n");
        
        // The customer at the front of the queue is the one whose getting his hair cut
		printf("Barber starts cutting hair of the new client..\n\n");
        
		// Success!
		return 0;
    }

	// Barber is not sleeping
    printf("Barber is busy.. So the client sits in a chair..\n\n");
    return 0;
}

int customer_leave() {
	// Dequeue returns -1 if queue is empty
    if (dequeue() != 0) { // 0 only if success
    	printf("\nNo customer to finish.. Barbershop is already empty!\n\n");
        return 0;
    }
    
    printf("\nBarber finished cutting hair of the current customer.\nCustomer leaves..\n\n", wait_queue -> front);
    
    // If wait_queue is empty, no customers in the barbershop
	if (wait_queue -> count == 0) {
    	printf("\nThe barber shop is now empty. Barber goes to sleep..\n\n");
        
		// Barber goes to sleep
		barber_sleeping = true;
    }
    
	return 0;    
}
