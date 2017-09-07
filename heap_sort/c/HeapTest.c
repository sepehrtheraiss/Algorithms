#include<stdio.h>
#include<stdlib.h>
#include "HeapSort.h"
int main()
{
    List l = newList();
    append(l,2);
    append(l,5);
    append(l,1);
    Heap h = newHeap(l);
    freeList(&l);
//    build_max_heap(h);
 //   printHeap(stdout,h);
    freeHeap(&h);
    return 0;
}
