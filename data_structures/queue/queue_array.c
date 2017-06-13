//
// Created by alan on 6/13/17.
//

#include "queue_array.h"

Queue* Queue_new();
void Queue_free(Queue* q);
char Queue_isEmpty(Queue* q)
{
    if (Queue_isValid(q))
        return (q->head == q->tail);
}

void Queue_put(Queue* q, int data);
int Queue_get(Queue* q);
char Queue_isValid(Queue* q)
{
    char state = (q == NULL);
    if (state)
    {
        fputs("Invalid queue pointer.\n", stderr);
    }
    return !state;
}