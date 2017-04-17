//
// Created by alan on 4/17/17.
//

#include "linkedList.h"

LinkedList* LinkedList_new()
{
    LinkedList* list = malloc(sizeof(LinkedList));

    if (list == NULL)
    {
        fprintf(stderr, "Failed to create new LinkedList.\n");
        exit(EXIT_FAILURE);
    }

    return list;
}

void LinkedList_put(LinkedList* list, char data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->pNext = NULL;

    Node* currentNode = list->start;

    // If empty list
    if (currentNode == NULL)
    {
        list->start = newNode;
    }
    else
    {
        while (currentNode != NULL)
            currentNode = currentNode->pNext;

        currentNode->pNext = newNode;
    }

}

void LinkedList_insert(LinkedList* list, unsigned int index, char data)
{
    if (index < 0)
    {
        fprintf(stderr, "Tried to insert element in list at negative index.\n");
        return;
    }

    // Empty list
    if (list->start == NULL)
    {
        fprintf(stderr, "Tried to insert element in empty list.\n");
        return;
    }

    // Insert at beginning
    if (index == 0)
    {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->pNext = list->start;

        list->start = newNode;
        return;
    }


    int i = 0;
    Node* prevNode = NULL;
    Node* currentNode = list->start;

    while (i != index)
    {
        prevNode = currentNode;
        currentNode = currentNode->pNext;
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->pNext = currentNode;

    prevNode->pNext = newNode;

}

char LinkedList_get(LinkedList* list, unsigned int index);

char LinkedList_pop(LinkedList* list, unsigned int index);

void LinkedList_delete(LinkedList* list, unsigned int index);

int LinkedList_isEmpty(LinkedList* list)
{
    return list->start == NULL;
}

void LinkedList_free(LinkedList* list)
{
    Node* prevNode = NULL;
    Node* currentNode = list->start;
    free(list);

    while (currentNode != NULL)
    {
        prevNode = currentNode;
        currentNode = currentNode->pNext;
        free(prevNode);
    }
}