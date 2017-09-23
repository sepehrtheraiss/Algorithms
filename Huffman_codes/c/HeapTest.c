#include "HeapSort.h"

int main()
{
    List l = newList();
    for(int i =0;i<5;i++){
        HeapNode* n = malloc(sizeof(HeapNode));
        n->key = i+1;
        n->data = "something"; //("i+%i",i+1);
        append(l,n);
    }
    printf("****************TEST CASE #1****************\n");
    printf("list size:%i\n",length(l));
    Heap h = newHeap(l);
    printf("heap size: %i\n",HeapSize(h));
    printf("heap size: %i\n",HeapLength(h));
    printHeap(stdout,h,'i');
    build_min_heap(h);
    printHeap(stdout,h,'p');
    printf("heap size: %i\n",HeapSize(h));
    printf("heap size: %i\n",HeapLength(h));
    printf("extract: %p\n",Heap_Extract_Min(h));
    printf("heap size: %i\n",HeapSize(h));
    printf("heap size: %i\n",HeapLength(h));
    printf("extract: %p\n",Heap_Extract_Min(h));
    printf("heap size: %i\n",HeapSize(h));
    printf("heap size: %i\n",HeapLength(h));
    printf("****************TEST CASE #2****************\n");
    printHeap(stdout,h,'i');
    HeapNode* n = malloc(sizeof(HeapNode));
    Min_Heap_Insert(h,2,n);
    printf("heap size: %i\n",HeapSize(h));
    printf("heap size: %i\n",HeapLength(h));
    printHeap(stdout,h,'i');
    freeHeap(&h);
    freeList(&l);
    return 0;
}
