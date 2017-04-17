//
// Created by alan on 4/17/17.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node{
    char data;
    Node* pNext;
};

struct LinkedList{
    Node* start;
};

LinkedList* LinkedList_new();
void LinkedList_put(LinkedList* list, char data);
void LinkedList_insert(LinkedList* list, unsigned int index, char data);
char LinkedList_get(LinkedList* list, unsigned int index);
char LinkedList_pop(LinkedList* list, unsigned int index);
void LinkedList_delete(LinkedList* list, unsigned int index);
int LinkedList_isEmpty(LinkedList* list);
int LinkedList_length(LinkedList* list);
void LinkedList_free(LinkedList* list);

#endif //LINKEDLIST_LINKEDLIST_H
