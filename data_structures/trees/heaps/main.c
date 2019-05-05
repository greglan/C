#include <stdio.h>
#include "minHeap.h"

int main() {
    MinHeap* t = MinHeap_new();

    MinHeap_free(t);
    return 0;
}