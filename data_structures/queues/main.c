#include <stdio.h>
#include "queue.h"

int main() {
    Queue* q = Queue_new();

    for(int i=0; i<5; i++)
        Queue_put(q, i);

    Queue_free(q);

    printf("Queue valid: %d.\n", Queue_isValid(q));

    q = Queue_new();
    for(int i=0; i<5; i++)
        Queue_put(q, i);

    for(int i=0; i<5; i++)
        printf("%d\n", Queue_get(q));

    return 0;
}