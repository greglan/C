//
// Created by alan on 6/13/17.
//

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

StackArray* Stack_new(int size);
void Stack_free(StackArray* s);
char Stack_isEmpty(StackArray* s);
void Stack_push(StackArray* s, int data);
int Stack_pop(StackArray* s);
char Stack_isValid(StackArray* s);

#endif //STACK_STACK_ARRAY_H
