#include "minHeap.h"

MinHeap* MinHeap_new()
{
    MinHeap* t = malloc(sizeof(MinHeap));

    if (t == NULL){
        fprintf(stderr, "Failed to allocate memory for MinHeap.\n");
    }
    else
    {
        t->root = NULL;
    }

    return t;
}

void MinHeap_swap();

void MinHeap_insert(MinHeap* t, int data)
{
    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL){
        fprintf(stderr, "Failed to allocate memory for new node.\n");
    }
    else
    {
        new_node->data = data;
        // Insert at the bottom of the tree
        // Dfs
    }
}

int MinHeap_get_min(MinHeap *t);

void MinHeap_Nodefree(Node* n)
{
    if (n != NULL)
    {
        MinHeap_Nodefree(n->lChild);
        MinHeap_Nodefree(n->rChild);
    }

    free(n);
}

void MinHeap_free(MinHeap* t)
{
    MinHeap_Nodefree(t->root);
    free(t);
}
