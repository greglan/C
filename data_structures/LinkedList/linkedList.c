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
    Node* prevNode = NULL;

    // If empty list
    if (currentNode == NULL)
    {
        list->start = newNode;
    }
    else
    {
        while (currentNode != NULL)
        {
            prevNode = currentNode;
            currentNode = currentNode->pNext;
        }

        prevNode->pNext = newNode;
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

    while (currentNode != NULL && i != index)
    {
        prevNode = currentNode;
        currentNode = currentNode->pNext;
        i++;
    }

    if (currentNode == NULL)
    {
        fprintf(stderr, "Tried to insert element at index greater than the list's length.\n");
    }
    else
    {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->pNext = currentNode;

        prevNode->pNext = newNode;
    }
}

char LinkedList_get(LinkedList* list, unsigned int index)
{
    if (index < 0)
    {
        fprintf(stderr, "Tried to get element in list at negative index.\n");
        return -1;
    }

    int i = 0;
    Node* currentNode = list->start;


    while (i != index)
    {
        currentNode = currentNode->pNext;
        i++;
    }

    return currentNode->data;
}

char LinkedList_pop(LinkedList* list, unsigned int index)
{
    if (index < 0)
    {
        fprintf(stderr, "Tried to pop element in list at negative index.\n");
        return -1;
    }

    int i = 0;
    Node* prevNode = NULL;
    Node* currentNode = list->start;

    while (i != index)
    {
        prevNode = currentNode;
        currentNode = currentNode->pNext;
        i++;
    }

    char data = currentNode->data;

    // If index=0
    if (prevNode == NULL) {
        list->start = NULL;
    }
    else
    {
        prevNode->pNext = currentNode->pNext;
    }

    free(currentNode);

    return data;
}

void LinkedList_delete(LinkedList* list, unsigned int index)
{
    LinkedList_pop(list, index);
}

int LinkedList_isEmpty(LinkedList* list)
{
    return list->start == NULL;
}

int LinkedList_length(LinkedList* list)
{
    int n = 0;
    Node* currentNode = list->start;

    while (currentNode != NULL)
    {
        currentNode = currentNode->pNext;
        n++;
    }

    return n;
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