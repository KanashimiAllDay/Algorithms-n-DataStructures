#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

// Macro will determinate how many element can hold stack.
#define MAX_STACK 1024

// Function will allocate more memory 
int expand_stack(unsigned*, unsigned*, void**, size_t);

// Macro initializes structure of stack with array of "type" elements and typedefs type for later varibles declaration.
// Also this macro defines a function for initialization stack variables
#define Stack(type) \
    struct stack_##type { \
        unsigned top, cap; \
        type *tabula; \
    }; \
    typedef struct stack_##type* Stack_##type; \
    Stack_##type init_##type##_stack() { \
        Stack_##type self = (Stack_##type) malloc(sizeof(struct stack_##type)); \
        self->top = 0; \
        self->cap = 1; \
        self->tabula = (type*) malloc(sizeof(type) * self->cap); \
        if(!self -> tabula) free(self); \
        return self; \
    } \

#define unpack_stack(unit) \
    &(unit)->top, &(unit)->cap, (void**)&(unit)->tabula, sizeof((unit)->tabula[(unit)->top - 1])
// Returns true if stack is empty otherwise false
#define isEmpty_stack(unit) \
    (!(unit)->top ? true : false)
// Returns true if stack is full otherwise false. "Full" means stack reached the limit MAX_STACK elements
// and no longer will allocates more memory
#define isFull_stack(unit) \
    (((unit)->top == MAX_STACK) ? true : false)
// Macro pushes el in back of unit.tabila and increase unit.top by one. unit->top == MAX_STACK means stack is full, add one more element will cause an overflow error
#define push_stack(unit, el) \
    (((unit)->top == MAX_STACK) ? (fprintf(stderr, "Overflow error\n"), exit(1)) : \
    (expand_stack(unpack_stack(unit)) ? (fprintf(stderr, "Realloc error\n"), exit(1)) : ((unit)->tabula[(unit)->top++] = (el)), 0))
// Macro decreases unit.top by one and returns unit.tabila[unit.top] element
#define pop_stack(unit) \
    (isEmpty_stack((unit)) ? (fprintf(stderr, "Underflow error\n"), exit(1), 0) : ((unit)->tabula[--(unit)->top]))
// Macro just returns unit.tabila[unit.top - 1] element
#define peek_stack(unit) \
    (isEmpty_stack((unit)) ? (fprintf(stderr, "Underflow error\n"), exit(1), 0) : ((unit)->tabula[(unit)->top - 1]))
// Always use this macro to free memory
#define free_stack(unit) \
    free((unit)->tabula); (unit)->tabula = NULL; \
    free((unit)); (unit) = NULL;

#endif // STACK_H