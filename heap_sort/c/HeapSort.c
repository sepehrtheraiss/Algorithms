#include "HeapSort.h"
#include "List.h"
// strcuts ---------------------------------------------------------------------

// private 
typedef struct HeapSortObj {
	int* A;
	int size;
	int length;
} HeapSortObj;
// constructors-Destructors ----------------------------------------------------

// returns reference to new empty max heap object 
Heap newHeap(List list){
	Heap h  = malloc(sizeof(HeapSortObj));
	h->A = malloc(sizeof(int)*length(list)); // A[0] will not be used
	h->length = h->size = length(list);

        for(int i = 1; i <= h->length; i++){
            A[i] = list.pop();
        }
	return h;
}

// pre: *pH != NULL , pH != NULL
void freeHeap(Heap* pH){
	if(pH != NULL && *pH != NULL){
		clearHeap(*pH);
		free(*pH);
		*pH = NULL;
	}
}


// Helper functions -------------------------------------------------------------
// returns index
int parent(int i){return i/2;}
int left(int i){return (i << 1);} // i *2 
int right(int i){return ((i << 1) | 1);}; // because I can and its faster
void swapHeap(Heap h,int i,int j){
   int temp =  h->A[i];
   h->A[i] = h->A[j];
   h->A[j] = temp;
}
// Access functions -------------------------------------------------------------

// Manipulation procedures --------------------------------------------------------

void max_heapify(Heap h,int i){
    int l = left(i);
    int r = right(i);
    int largest = 0;
    if (l <= h->size && h->A[l] > h->A[i] ){
        largest = l;
    }
    else{
        largest = i;
    }

    if (r <= h->size && h->A[r] > h->A[largest] ){
        largest = r;
    }
    if (largest != i){
        swapHeap(h,largest,i);
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
	#n->A = 
	n->length = h->length;
	n->size = h->size;
	return n;
}
