#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Node Node;
typedef struct Queue Queue;

struct Node{
    int data;
    Node* next;
};

struct Queue{
    Node* head;
    Node* last;
};

Queue* Queue_new();
void Queue_free(Queue* q);
char Queue_isEmpty(Queue* q);
void Queue_put(Queue* q, int data);
int Queue_get(Queue* q);
char Queue_isValid(Queue* q);
char Queue_NodeisValid(Node* node);
#endif //QUEUE_QUEUE_H
