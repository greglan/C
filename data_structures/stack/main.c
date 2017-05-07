#include <stdio.h>
#include "stack.h"

int main() {
    Stack* s = Stack_new();

    for(int i=0; i<5; i++)
        Stack_push(s, i);

    Stack_free(s);

    Stack_isValid(s);

    s = Stack_new();
    for(int i=0; i<5; i++)
        Stack_push(s, i);

    for(int i=0; i<5; i++)
        printf("%d\n", Stack_pop(s));

    return 0;
}