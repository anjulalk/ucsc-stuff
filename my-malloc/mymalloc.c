#include <stdio.h>
#include <stdbool.h>
#define MEMSIZE 25000
#define MINSIZE 4
#define MEMLIMIT (void*) mem + MEMSIZE - (sizeof(meta) + MINSIZE)

typedef struct meta {
    bool hole;
    unsigned int size;
    struct meta *prev;
 } meta;

char mem[MEMSIZE];
meta* head = (meta*) mem;

bool init = false;

void *MyMalloc(unsigned int size) {
    meta *m = head, *n;

    if (size < 1) return NULL;
    if (!init) {
        head -> hole = true;
        head -> size = MEMSIZE - sizeof(meta); //25000 - 16 = 24984
        head -> prev = NULL;
        init = true;
    }

    //traverse
    while ((void*) m <= MEMLIMIT) {
        //check
        if (m -> hole == true && m -> size >= size) {    
            if (m -> size == size) m -> hole = false; //bingo!
            else if (m -> size > size) {
                //split
                n = (meta*) ((void*) m + sizeof(meta) + size); //next meta
                if ((void*) n <= MEMLIMIT) {
                        //enough space left for another chunk
                        n -> hole = true;
                        n -> size = m -> size - (sizeof(meta) + size); 
                        n -> prev = m;
                }
            
                m -> hole = false;
                m -> size = size;
            }

            return (void*) m + sizeof(meta); //success
        }

        //advance onto next meta block
        m = (meta*) ((void*) m + sizeof(meta) + m -> size); 
    }

    return NULL; //not enough space
}

void MyFree(void* address) {
    meta* m = (void*) address - sizeof(meta);
    meta *p = m -> prev; //previous block
    meta *n = (void*) m + sizeof(meta) + m -> size; //next block
    meta *o = (void*) n + sizeof(meta) + n -> size; //block after next block

    bool p_m_merge = false, m_n_merge = false, o_exist = false;

    if (!init) return; //uninitialized

    if (p != NULL && p -> hole == true) p_m_merge = true;
    if ((void*) n <= MEMLIMIT && n -> hole == true) m_n_merge = true;
    // if o exist then o -> prev must be set
    if ((void*) o <= MEMLIMIT) o_exist = true;
    
    if (!p_m_merge && !m_n_merge) m -> hole = true; //bingo!!!
    
    if (m_n_merge) {
        //expand m over n
        m -> size += sizeof(meta) + n -> size;
        m -> hole = true;
        
        if (o_exist) o -> prev = m;
    }
    
    if (p_m_merge) {
        //expand p over m
        p -> size += sizeof(meta) + m -> size;   
        
        if (o_exist && m_n_merge) o -> prev = p;
        else n -> prev = p;
    }

    return;
}