#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/*
    Function will double allocated memory for stack.tabula if needed 
    and if there are less number of elements in tabula than MAX_STACK macro.
*/
int expand_stack(unsigned* top, unsigned* cap, void** data, size_t memsize) {
    if(*top + 1 > *cap) {
        void* ptr;
        *cap <<= 1;
        ptr = realloc(*data, *cap * memsize);
        if(!ptr) return -1;
        *data = ptr;
    }
    return 0;
}