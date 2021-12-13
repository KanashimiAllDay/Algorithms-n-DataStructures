# stack
A type-safe dynamic stack implementation in C programming language.

## Installation
The [stack.c] (stack.c?raw=1) and [stack.h] (stack.h?raw=1) files can be dropped into an existing C project and compiled a long with it.

## Usage
Before using a stack data type object it should first be initialised using the `Stack("type")` macro.
```c
Stack(int)
Stack(double)
// etc...
```

After initialization of a stack data type object you have Stack_"type" data type. 
You should initialised Stack_"type" variable using init_"type"_stack() function.
!!! Stack_"type" is a pointer to a stack, not a stack object itself.
```c
Stack_int name_of_var = init_int_stack();
Stack_double other_name = init_double_stack();
```

To define a stack with new data type you should typedefs it and then initialized stack with new data type.
```c
typedef unsigned long Time;
Stack(Time)

// ... //

Stack_Time name_of_var = init_Time_stack();

// ... //
```

## Functions and macros
All stack functions are macro functions. The parameter `unit` in each macro should be a pointer to the stack.

### MAX\_STACK
Macro will determinate how many element can hold stack and how much memory will be allocated. 1024 elements by default.

### isEmpty\_stack(unit)
Returns `true` if stack is empty otherwise `false`.

### isFull\_stack(unit)
Returns `true` if stack is full otherwise `false`. "Full" means stack reached the limit MAX_STACK elements (top of stack `== MAX_STACK`) and no longer will allocate more memory.

### push\_stack(unit, el) 
Macro pushes `el` in end of stack and increases stack's top by one. If stack's top `== MAX_STACK` so that means stack is full, add one more element will cause an overflow error.

### pop\_stack(unit)
Macro returns last element and removes it from stack. If stack is empty will cause an underflow error.

### peek\_stack(unit)
Macro just returns last element in stack. If stack is empty will cause an underflow error.

### free\_stack(unit)
Deinitialises the stack, freeing the memory the stack allocated during use; this should be called when we're finished with a stack.

## Example

```c
#include <stdio.h>
#include "stack.h"

Stack(int)

int main(void) {
    Stack_int numbers = init_int_stack();
    for(size_t i = 0; !isFull_stack(numbers); ++i)
        push_stack(numbers, i);
    for(size_t i = 0; !isEmpty_stack(numbers); ++i)
        printf("%d\n", pop_stack(numbers));
    free_stack(numbers);
    return 0;
}
```