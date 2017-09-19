#include "HeapSort.h"

int main()
{
    List l = newList();
    for(int i =0;i<5;i++){
        HeapNode* n = malloc(sizeof(HeapNode));
        n->key = i+1;
        n->data = "something";
        append(l,n);
    }
    printf("****************TEST CASE #1****************\n");
    printf("list size:%i\n",length(l));
    Heap h = newHeap(l);
    printf("heap size:%i length:%i\n",HeapSize(h),HeapLength(h));
    build_min_heap(h);
    printHeap(stdout,h,'s');
    printf("****************TEST CASE #2****************\n");
    heap_sort(h);
    printHeap(stdout,h,'s');
    Heap_Decrease_Key(h,3,0);
    printHeap(stdout,h,'s');
    printf("heap size:%i length:%i\n",HeapSize(h),HeapLength(h));
    clearHeap(h);
    printHeap(stdout,h,'s');
    printf("heap size:%i length:%i\n",HeapSize(h),HeapLength(h));
    printf("****************TEST CASE #3****************\n");
    //printf("heap min: %i\n",Heap_Minimum(h)->key);
    //printf("heap EXtract min: %i\n",Heap_Extract_Min(h)->key);
    Min_Heap_Insert(h,2,"ahan");
    Min_Heap_Insert(h,3,"areh!");
    Min_Heap_Insert(h,4,"jonam!");
    printHeap(stdout,h,'s');
    freeHeap(&h);
    printf("****************TEST CASE #4****************\n");
     for(int i =0;i<5;i++){
        HeapNode* n = malloc(sizeof(HeapNode));
        n->key = i+1;
        n->data = "something";
        append(l,n);
    }
    h = newHeap(l);
    printHeap(stdout,h,'s');
    printf("heap size:%i length:%i\n",HeapSize(h),HeapLength(h));
    build_min_heap(h);
    printHeap(stdout,h,'s');
    Min_Heap_Insert(h,0,"ahan");
    Min_Heap_Insert(h,2,"areh!");
    Min_Heap_Insert(h,6,"ghorbonet!");
    Min_Heap_Insert(h,8,"MIRAM!");
    Min_Heap_Insert(h,10,"PAS CHI!!");
    printHeap(stdout,h,'s');
    HeapNode* n = Heap_Extract_Min(h);
    printf("key:%i data:%s\n",n->key,n->data);
    freeHeap(&h);
    freeList(&l);
    return 0;
}
