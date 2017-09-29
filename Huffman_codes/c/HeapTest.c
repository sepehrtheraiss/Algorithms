#include "HeapSort.h"

int main()
{
    List l = newList();
    HeapNode* n = NULL;
    printf("size of heap node: %i\n",sizeof(HeapNode));
    for(int i =0;i<5;i++){
        n = malloc(sizeof(HeapNode));
        n->key = i+1;
        n->data = malloc(sizeof(HeapNode));
        append(l,n);
    }
    printList(stdout,l,'n');
    Heap h = newHeap(l);
    build_min_heap(h);
    printHeap(stdout,h,'n');
    printf("size: %i\n",HeapSize(h));
    printHeapMemAddress(h);
    n = Heap_Extract_Min(h);
    printf("extract  n: %p key: %i\n",n,n->key);
    printHeapMemAddress(h);
    printf("size: %i\n",HeapSize(h));
    printHeap(stdout,h,'n');
//    n = malloc(sizeof(HeapNode));
  //  n->data = malloc(sizeof(HeapNode));
  //  Min_Heap_Insert(h,1,n);
    printHeap(stdout,h,'n');
    printf("free Heap\n");
    freeHeap(&h);
    printf("free list\n");
    freeList(&l);
    return 0;
}
