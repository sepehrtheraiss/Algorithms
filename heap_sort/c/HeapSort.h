#ifndef _HEAP_SORT_H_INCLUDE_
#define _HEAP_SORT_H_INCLUDE_

// max-heapify O(lg n) maintains the max heap property
// build max heap O(n) produces a max heap from an unordered input array
// heaposort O(n lg n) sorts an array 
// max-heap-insert, heap-extract-max, heap-increase-key and heap-maximum O(lg n) implementation for priority queue

typedef struct HeapSortObj* Heap;

// constructors-Destructors ----------------------------------------------------

// returns reference to new empty max heap object 
Heap newHeap(void);

// pre: *pH != NULL , pH != NULL
void freeHeap(Heap* pH);

// Access functions -------------------------------------------------------------

// returns index
int parent(int i);
int left(int i);
int right(int i);

// Manipulation procedures --------------------------------------------------------

void max_heapify(Heap h,int i);
void build_max_heap(Heap h);
void heap_sort(Heap h);
void clear(Heap h);
void printHeap(FILE* out,Heap h);

Heap copyHeap(Heap h);
#endif
