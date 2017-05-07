//
// Created by alan on 5/5/17.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Node Node;
typedef struct Stack Stack;

struct Node{
    int data;
    Node* previous;
};

struct Stack{
    Node* head;
};

Stack* Stack_new();
void Stack_free(Stack* s);
unsigned char Stack_isEmpty(Stack* s);
void Stack_push(Stack* s, int data);
int Stack_pop(Stack* s);
unsigned char Stack_isValid(Stack* s);
unsigned char Stack_NodeisValid(Node* s);

#endif //STACK_STACK_H
