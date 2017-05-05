//
// Created by alan on 5/5/17.
//

#include "stack.h"

// FIXME: check if stack is not null

Stack* Stack_new()
{
    Stack* s = malloc(sizeof(Stack));

    if (s == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for new stack.");
    }
    else
    {
        s->head = NULL;
    }

    return s;
}

unsigned char Stack_isEmpty(Stack* s)
{
    return (s->head == NULL);
}

void Stack_push(Stack* s, int data)
{
    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for new stack.");
    }
    else
    {
        new_node->data = data;

        if (Stack_isEmpty(s))
        {
            s->head = new_node;
        }
        else
        {
            Node* head = s->head;
            head->next = new_node;
            s->head = new_node;
        }
    }
}

int Stack_pop(Stack* s)
{
    Node* head = s->head;
    s->head = head->
}