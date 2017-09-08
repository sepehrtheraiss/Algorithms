#include<stdio.h>
#include<stdlib.h>
#include "HeapSort.h"
int main()
{
    List l = newList();
    append(l,2);
    append(l,5);
    append(l,10);
    append(l,1);
    Heap h = newHeap(l);
    freeList(&l);
/*    build_max_heap(h);
    printHeap(stdout,h);
    printf("max: %i\n",Heap_Maximum(h));
    printf("extract max: %i\n",Heap_Extract_Max(h));
    printf("max: %i\n",Heap_Maximum(h));
    printHeap(stdout,h);
    printf("increase key\n");
    Heap_Increase_Key(h,3,6);
    printHeapMemAddress(h);
    printf("insert 9\n");
    Max_Heap_Insert(h,9);
    printHeap(stdout,h);
    printf("max insert 10 11,12,13,14,15\n");
    Max_Heap_Insert(h,10);
    Max_Heap_Insert(h,11);
    Max_Heap_Insert(h,12);
    Max_Heap_Insert(h,13);
    Max_Heap_Insert(h,14);
    Max_Heap_Insert(h,15);
    printHeap(stdout,h);
    printHeapMemAddress(h);
    Heap copy = copyHeap(h);
    printHeap(stdout,copy);
    freeHeap(&copy);*/
    // min heap test
    build_min_heap(h);
    printHeap(stdout,h);
    printf("min: %i\n",Heap_Minimum(h));
    printf("extract max: %i\n",Heap_Extract_Min(h));
    printf("min: %i\n",Heap_Minimum(h));
    printHeap(stdout,h);
    printf("decrease key 3 3\n");
    Heap_Decrease_Key(h,3,3);
    printHeap(stdout,h);
    printf("min insert 9\n");
    Min_Heap_Insert(h,9);
    printHeap(stdout,h);
    printf("extract min: %i\n",Heap_Extract_Min(h));
    printHeap(stdout,h);
    printf("min insert 10 11,12,13,14,15\n");
    Min_Heap_Insert(h,10);
    Min_Heap_Insert(h,11);
    Min_Heap_Insert(h,12);
    Min_Heap_Insert(h,13);
    Min_Heap_Insert(h,14);
    Min_Heap_Insert(h,15);
    printHeap(stdout,h);
    Heap_Decrease_Key(h,2,1);
    printHeap(stdout,h);
    freeHeap(&h);
    return 0;
}
