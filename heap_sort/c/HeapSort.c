#include "./HeapSort.h"

// strcuts ---------------------------------------------------------------------

// private 
typedef struct HeapSortObj {
	List list = newList();
	int size;
	int length;
} HeapSortObj;
// constructors-Destructors ----------------------------------------------------

// returns reference to new empty max heap object 
Heap newHeap(void){
	Heap h    = malloc(sizeof(HeapSortObj));
	h->size   = 0;
	h->length = 0;
	return h;
}

// pre: *pH != NULL , pH != NULL
void freeHeap(Heap* pH){
	if(pH != NULL && *pH != NULL){
		freeHeap(*pH);
		free(*pH);
		*pH = NULL;
	}
}

// Access functions -------------------------------------------------------------

// returns index
int parent(int i){return i/2;}
int left(int i){return (i << 1);} // i *2 
int right(int i){return ((i << 1) | 1);}; // because I can and its faster


// Manipulation procedures --------------------------------------------------------

void max_heapify(Heap h,int i){
	int l = left(i);
    int r = right(i);
    int largest = 0;
    if (l <= h->size && A[l] > A[i]){
        largest = l;
    }
    else{
        largest = i;
    }

    if (r <= h->size && atIndex(h->list,r) > atIndex(h->list,largest){
        largest = r;
    }
    if (largest != i){
        swap(h,largest,i);
        max_heapify(h,largest);
    }
}
void build_max_heap(Heap h){
	elements = length();
    for (int i = length()/2;i >=1; i--){
        max_heapify(h,i);
    }
}
}
void heap_sort(Heap h){
	 build_max_heap(h);
    for (int i = length(); i >= 2;i--){
        swap(h->list,1,i);
        h->size--;
        max_heapify(h,1);
    }
}
void clearHeap(Heap h){
	clear(h->list);
	h->length = 0;
	h->size = 0;
}
void printHeap(FILE* out,Heap h){
	printList(out,h->list);
}

Heap copyHeap(Heap h){
	if (h == NULL){
		printf("Heap Error: calling copyHeap() on NULL Heap reference\n");
		exit(EXIT_FAILURE);
	}
	Heap n = newHeap();
	n->list = copyList(h->list);
	n->length = h->length;
	n->size = h->size;
	return n;
}