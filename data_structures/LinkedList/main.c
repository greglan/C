#include <stdio.h>

#include "linkedList.h"

int main() {
    LinkedList* list = LinkedList_new();

    LinkedList_put(list, 'c');
    LinkedList_insert(list, 0, 'a');
    LinkedList_insert(list, 1, 'b');

    LinkedList_insert(list, 3, 'x');
    LinkedList_get(list, 0);
    LinkedList_pop(list, 2);

    LinkedList_delete(list, 1);
    LinkedList_delete(list, 0);
    LinkedList_isEmpty(list);

    LinkedList_put(list, 'a');
    LinkedList_put(list, 'b');
    LinkedList_put(list, 'c');

    LinkedList_free(list);

    return 0;
}