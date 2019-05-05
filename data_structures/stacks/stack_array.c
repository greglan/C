// TODO: test the prog using main func

#include "stack_array.h"

StackArray* StackArray_new(int size)
{
    StackArray* stack = malloc(sizeof(StackArray));
    stack->size = size;
    stack->head = 0;
    stack->data = malloc(size* sizeof(int));

    return stack;
}

void StackArray_free(StackArray *s)
{
    if (StackArray_is_valid(s))
    {
        free(s->data);
        free(s);
    }
}

char StackArray_is_empty(StackArray *s)
{
    return (s->head == 0);
}

void StackArray_push(StackArray *s, int data)
{
    if (StackArray_is_valid(s))
    {
        if (s->head+1 < s->size)
        {
            s->head++;
            s->data[s->head] = data;
        }
    }
}

int StackArray_pop(StackArray *s)
{
    if (StackArray_is_valid(s))
    {
        if (!StackArray_is_empty(s))
        {
            s->head--;
           return s->data[s->head+1];
        }
    }
}

char StackArray_is_valid(StackArray *s)
{
    char state = (s == NULL);
    if (state)
    {
        fputs("Invalid stack pointer.\n", stderr);
    }
    return !state;
}