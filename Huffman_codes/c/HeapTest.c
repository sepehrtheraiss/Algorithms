#include "HeapSort.h"

int main()
{
    List l = newList();
    for(int i =0;i<5;i++){
        node* n = malloc(sizeof(node));
        n->key = i;
        n->data = "something";
        append(l,n);
    }
    Heap h = newHeap(l);
    build_min_heap(h);
    printHeap(stdout,h,'s');
    printf("key:%i\n",Heap_Minimum(h)->key);
    printf("key:%i\n",Heap_Extract_Min(h)->key);
//    printf("key:%i\n",Heap_Extract_Min(h)->key);
    printf("key:%i\n",Heap_Minimum(h)->key);
    printHeap(stdout,h,'s');
    Heap_Decrease_Key(h,2,0);
    printf("minimum key:%i\n",Heap_Minimum(h)->key);
    printHeap(stdout,h,'s');
    Min_Heap_Insert(h,5,"areh");
    printHeap(stdout,h,'s');
    freeHeap(&h);
    freeList(&l);
    return 0;
}
