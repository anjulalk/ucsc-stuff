//Defines the node type required for the program
typedef struct block {
    int begin_address;
    int end_address;
    int size;
    bool hole;
    int process_id;
    struct block *next;
} block;