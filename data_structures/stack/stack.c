//
// Created by alan on 5/5/17.
//

#include "stack.h"

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

void Stack_free(Stack* s)
{
    if (Stack_isValid(s))
    {
        while (!Stack_isEmpty(s))
            Stack_pop(s);
        free(s);
    }
}

char Stack_isEmpty(Stack* s)
{
    if (Stack_isValid(s))
    {
        return (s->head == NULL);
    }
    else
        return 1;
}

void Stack_push(Stack* s, int data)
{
    if (Stack_isValid(s))
    {
        Node* new_node = malloc(sizeof(Node));

        if (!Stack_NodeisValid(new_node))
        {
            fputs("Failed to allocate memory for new node.\n", stderr);
        }
        else
        {
            new_node->data = data;

            if (Stack_isEmpty(s))
            {
                s->head = new_node;
                new_node->previous = NULL;
            }
            else
            {
                Node* head = s->head;
                new_node->previous = head;
                s->head = new_node;
            }
        }
    }
}

int Stack_pop(Stack* s)
{
    if (Stack_isValid(s))
    {
        if (!Stack_isEmpty(s))
        {
            Node* head = s->head;
            s->head = head->previous;

            int data = head->data;
            free(head);

            return data;
        }
        else
        {
            fputs("Pop from empty stack.\n", stderr);
        }
    }
}

char Stack_isValid(Stack* s)
{
    char state = (s == NULL);
    if (state)
    {
        fputs("Invalid stack pointer.\n", stderr);
    }
    return !state;
}

char Stack_NodeisValid(Node* s)
{
    char state = (s == NULL);
    if (state)
    {
        fputs("Invalid node pointer.\n", stderr);
    }
    return !state;
}