//
// Created by alan on 6/13/17.
// TODO: test the prog using main func

#include "stack_array.h"

StackArray* Stack_new(int size)
{
    StackArray* stack = malloc(sizeof(StackArray));
    stack->size = size;
    stack->head = 0;
    stack->data = malloc(size* sizeof(int));

    return stack;
}

void Stack_free(StackArray* s)
{
    if (Stack_isValid(s))
    {
        free(s->data);
        free(s);
    }
}

char Stack_isEmpty(StackArray* s)
{
    return (s->head == 0);
}

void Stack_push(StackArray* s, int data)
{
    if (Stack_isValid(s))
    {
        if (s->head+1 < s->size)
        {
            s->head++;
            s->data[s->head] = data;
        }
    }
}

int Stack_pop(StackArray* s)
{
    if (Stack_isValid(s))
    {
        if (!Stack_isEmpty(s))
        {
            s->head--;
           return s->data[s->head+1];
        }
    }
}

char Stack_isValid(StackArray* s)
{
    char state = (s == NULL);
    if (state)
    {
        fputs("Invalid stack pointer.\n", stderr);
    }
    return !state;
}