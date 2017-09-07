#ifndef _HEAP_SORT_H_INCLUDE_
#define _HEAP_SORT_H_INCLUDE_

#include<stdio.h>
#include<stdlib.h>
#include "List.h"
// max-heapify O(lg n) maintains the max heap property
// build max heap O(n) produces a max heap from an unordered input array
// heaposort O(n lg n) sorts an array 
// max-heap-insert, heap-extract-max, heap-increase-key and heap-maximum O(lg n) implementation for priority queue

typedef struct HeapSortObj* Heap;

// constructors-Destructors ----------------------------------------------------

// returns reference to new empty max heap object 
Heap newHeap(List list);

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
void clearHeap(Heap h);
void printHeap(FILE* out,Heap h);

// priority queue
int Heap_Maximum(Heap h);
int Heap_Extract_Max(Heap h);
void Heap_Increase_key(Heap h,int i,int key);
void Max_Heap_Insert(Heap h,int key);
Heap copyHeap(Heap h);

#endif
