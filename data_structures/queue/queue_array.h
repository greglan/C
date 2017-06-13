//
// Created by alan on 6/13/17.
//

#ifndef SCRIPTS_QUEUE_ARRAY_H
#define SCRIPTS_QUEUE_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Queue{
    int size;
    int head;
    int tail;
    int* data;
};

Queue* Queue_new();
void Queue_free(Queue* q);
char Queue_isEmpty(Queue* q);
void Queue_put(Queue* q, int data);
int Queue_get(Queue* q);
char Queue_isValid(Queue* q);
#endif //SCRIPTS_QUEUE_ARRAY_H
