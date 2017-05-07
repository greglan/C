//
// Created by alan on 5/7/17.
//

#include "queue.h"

Queue* Queue_new()
{
    Queue* q = malloc(sizeof(Queue));

    if (q == NULL)
    {
        fputs("Failed to allocate memory for new queue.\n", stderr);
    }
    else
    {
        q->head = NULL;
        q->last = NULL;
    }

    return q;
}

void Queue_free(Queue* q)
{
    if (Queue_isValid(q))
    {
        while (!Queue_isEmpty(q))
            Queue_get(q);
        free(q);
    }
}

char Queue_isEmpty(Queue* q)
{
    if (Queue_isValid(q))
    {
        return (q->head == NULL);
    }
    else
        return 1;
}

void Queue_put(Queue* q, int data)
{
    if (Queue_isValid(q))
    {
        Node* new_node = malloc(sizeof(Node));

        if (!Queue_NodeisValid(new_node))
        {
            fputs("Failed to allocate memory for new node.\n", stderr);
        }
        else
        {
            new_node->data = data;
            new_node->next = NULL;

            if (Queue_isEmpty(q))
            {
                q->head = new_node;
                q->last = new_node;
            }
            else
            {
                Node* last = q->last;
                last->next = new_node;
                q->last = new_node;
            }
        }
    }
}

int Queue_get(Queue* q)
{
    if (Queue_isValid(q))
    {
        if (!Queue_isEmpty(q))
        {
            Node* head = q->head;
            q->head = head->next;

            int data = head->data;
            free(head);

            return data;
        }
        else
        {
            fputs("Get from empty queue.\n", stderr);
        }
    }
}

char Queue_isValid(Queue* q)
{
    char state = (q == NULL);
    if (state)
    {
        fputs("Invalid queue pointer.\n", stderr);
    }

    return !state;
}

char Queue_NodeisValid(Node* node)
{
    char state = (node == NULL);
    if (state)
    {
        fputs("Invalid node pointer.\n", stderr);
    }
    return !state;
}