#include <stdio.h>
#include <stdbool.h>
#define MEMSIZE 25000
#define verboseprintf if (verbose) printf

//structure for meta
typedef struct meta {
    bool hole;
    unsigned int size;
    struct meta *prev;
 } meta;

char mem[MEMSIZE];
meta* head = (meta*) mem;

//debug
bool verbose = true;
bool init = false;

void *MyMalloc(unsigned int size) {
    //invalid size
    if (size < 1) return NULL;

    //init
    if (!init) {
        head -> hole = true;
        head -> size = MEMSIZE - sizeof(meta);
        head -> prev = NULL;
        init = true;
    }

    //traverse
    meta *m = head, *n, *_n; //_n = next expected metadata
    while (true) {
        if (m -> hole == false || (m -> hole = true && m -> size < size)) {
            //not suitable
            _n = (meta*) ((void*) m + sizeof(meta) + m -> size);
            if ((void*) _n >= (void*) mem + MEMSIZE) return NULL;

            //advance
            m = _n;
            continue;
        }

        if (m -> size == size) m -> hole = false; //bingo!
        else if (m -> size > size) {
            //split            
            n = (meta*) ((void*) m + sizeof(meta) + size);

            n -> hole = true;
            m -> hole = false;
            n -> size = m -> size - size - sizeof(meta); 
            m -> size = size;
            n -> prev = m;
        }
        break;
    }

    return (void*) m + sizeof(meta);
}

void MyFree(void* address) {
    if (!init) return; //uninitialized

    meta* m = (void*) address - sizeof(meta);
    meta *n = (void*) m + sizeof(meta) + m -> size;
    meta *_n = (void*) n + sizeof(meta) + n -> size; //_n = expected metadata after n
    meta *p = m -> prev;

    bool expand_p = false, expand_n = false, _n_exist = false;

    if (p != NULL && p -> hole == true) expand_p = true;
    if ((void*) n <= (void*) &mem[MEMSIZE - sizeof(meta) - 1] && n -> hole == true) expand_n = true;
    if ((void*) _n <= (void*) &mem[MEMSIZE - sizeof(meta) - 1]) _n_exist = true;

    if (!expand_n && !expand_p) m -> hole = true; //bingo again!
    else if (expand_n) {
        //expand m over n
        m -> size = m -> size + sizeof(meta) + n -> size;
        m -> hole = true;

        if (_n_exist) _n -> prev = m;
    }
    else if (expand_p) {
        //expand p over m
        p -> size = p -> size + sizeof(meta) + m -> size;   
        
        if (_n_exist && expand_n) _n -> prev = p;
        else n -> prev = p;
    }

    return;
}