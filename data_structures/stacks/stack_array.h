#ifndef STACK_STACK_ARRAY_H
#define STACK_STACK_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StackArray StackArray;

struct StackArray{
    int size;
    int head; // Index of the head of the stack
    int* data;
};

StackArray* StackArray_new(int size);
void StackArray_free(StackArray *s);
char StackArray_is_empty(StackArray *s);
void StackArray_push(StackArray *s, int data);
int StackArray_pop(StackArray *s);
char StackArray_is_valid(StackArray *s);

#endif //STACK_STACK_ARRAY_H
