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
	h->A = malloc( sizeof(int)* (length(list)+1) ) ; // A[0] will not be used
	h->length = h->size = length(list);
        for(int i = 1; i <= h->length; i++){
            h->A[i] = pop(list);
        }
	return h;
}

// pre: *pH != NULL , pH != NULL
void freeHeap(Heap* pH){
	if(pH != NULL && *pH != NULL){
	//	clearHeap(*pH);
                free((*pH)->A);
	        (*pH)->length = 0;
	        (*pH)->size = 0;
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
	h->size = h->length;
    for (int i = h->length/2;i >=1; i--){
        max_heapify(h,i);
    }
}
void heap_sort(Heap h){
    build_max_heap(h);
    for (int i = h->length; i >= 2;i--){
        swapHeap(h,1,i);
        h->size--;
        max_heapify(h,1);
    }
}
void clearHeap(Heap h){
	free(h->A);
	h->length = 0;
	h->size = 0;
}
void printHeap(FILE* out,Heap h){
    fprintf(out,"A: ");
    for (int i = 1; i<= h->length; i++){
        fprintf(out,"%i ",h->A[i]);
    }
    fprintf(out,"\n");
}

int Heap_Maximum(Heap h){
    if(h != NULL){
        return h->A[1];
    }
    else{
        fprintf(stderr,"Heap == NULL\n");
        exit(1);
    }
}
int Heap_Extract_Max(Heap h){
    if(h->size < 1){
        fprintf(stderr,"heap underflow\n");
        exit(1);
    }
    int max = h->A[1];
    h->A[1] = h->A[h->size];
    h->size--;
    max_heapify(h,1);
    return max;
}

void Heap_Increase_Key(Heap h,int i,int key){
    if(key < h->A[i]){
        fprintf(stderr,"new key is smaller than current key\n");
    }
    h->A[i] = key;
    while (i > 1 && h->A[parent(i)] < h->A[i]){
        swapHeap(h,i,parent(i));
        i = parent(i);
    }
}

void Max_Heap_Insert(Heap h,int key){
    h->size++;
    h->A[h->size] = -9999;
    //Heap_Increase_key(h,h->size,key);
}

Heap copyHeap(Heap h){
    if (h == NULL){
	    printf("Heap Error: calling copyHeap() on NULL Heap reference\n");
	    exit(EXIT_FAILURE);
    }
    Heap copy = malloc(sizeof(HeapSortObj));
    copy->A = malloc(sizeof(int)* (h->length+1) ); 
    copy->length = copy->size = h->length;
    for(int i = 1; i <= copy->length; i++){
        copy->A[i] = h->A[i];
    }
    return copy;
}