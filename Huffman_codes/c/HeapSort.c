#include "HeapSort.h"
#include <limits.h>
// strcuts ---------------------------------------------------------------------
//typedef struct HeapNode{int key;void* data;}HeapNode;
typedef struct HeapSortObj {
        HeapNode** A;
	int size;
	int length;
} HeapSortObj;
// constructors-Destructors ----------------------------------------------------

// returns reference to new empty max heap object 
Heap newHeap(List list){
	Heap h  = malloc(sizeof(HeapSortObj));
	h->A = malloc( sizeof(HeapNode)* (length(list)+1) ) ; // A[0] will not be used
	h->length = h->size = length(list);
        for(int i = 1; i <= h->length; i++){
            h->A[i] = (HeapNode *)pop(list);
        }
	return h;
}

// pre: *pH != NULL , pH != NULL
void freeHeap(Heap* pH){
	if(pH != NULL && *pH != NULL){
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
   HeapNode* temp =  h->A[i];
   h->A[i] = h->A[j];
   h->A[j] = temp;
}
void printHeapMemAddress(Heap h){
    printf("A memory address: \n");
    for(int i = 1; i <= h->size; i++){
        printf("%p \n",&h->A[i]);
    }
    //printf("\n");
}
int HeapLength(Heap h){
    return h->length;
}
int HeapSize(Heap h){
    return h->size;
}
void clearHeap(Heap h){
	free(h->A);
        h->A = NULL;
	h->length = 0;
	h->size = 0;
}
void printHeap(FILE* out,Heap h,char type){
    fprintf(out,"------Heap HeapNodes------\n");
    for (int i = 1; i<= h->size; i++){
        switch (type){
            case 'i':
                fprintf(out,"key:%i data:%i\n",h->A[i]->key,*(int *)h->A[i]->data);
                break;
            case 's':
                fprintf(out,"key:%i data:%s\n",h->A[i]->key,(char *)h->A[i]->data);
                break;
            case 'c':
                fprintf(out,"key:%i data:%c\n",h->A[i]->key,*(char *)h->A[i]->data); // how it worked ? I have data->c and other stuff, it takes the first pointer somehow
                break;
            default:
                fprintf(out,"key:%i data:%p\n",h->A[i]->key,h->A[i]->data);
                break;
        }
    }
   /* for (int i = 1; i<= h->size; i++){
        fprintf(out,"key:%i data:%s\n",h->A[i]->key,(char *)h->A[i]->data);
    }*/
    fprintf(out,"------Heap HeapNodes------\n");
}

Heap copyHeap(Heap h){
    if (h == NULL){
	    printf("Heap Error: calling copyHeap() on NULL Heap reference\n");
	    exit(EXIT_FAILURE);
    }
    Heap copy = malloc(sizeof(HeapSortObj));
    copy->A = malloc(sizeof(HeapNode) * (h->size+1) ); 
    copy->length = h->length;
    copy->size = h->size; 
    for(int i = 1; i <= copy->size; i++){
        copy->A[i] = h->A[i];
    }
    return copy;
}

// Max Heap Sort  -------------------------------------------------------------


void max_heapify(Heap h,int i){
    int l = left(i);
    int r = right(i);
    int largest = 0;
    if (l <= h->size && h->A[l]->key > h->A[i]->key ){
        largest = l;
    }
    else{
        largest = i;
    }

    if (r <= h->size && h->A[r]->key > h->A[largest]->key ){
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
    h->size = h->length;
}
// Max priority queue
HeapNode* Heap_Maximum(Heap h){
    if(h != NULL && h->size != 0){
        return h->A[1];
    }
    else{
        fprintf(stderr,"Heap == NULL || size == 0\n");
        exit(EXIT_FAILURE);
    }
}
HeapNode* Heap_Extract_Max(Heap h){
    if(h->size < 1){
        fprintf(stderr,"heap underflow\n");
        exit(EXIT_FAILURE);
    }
    HeapNode* max = h->A[1];
    h->A[1] = h->A[h->size];
    h->size--;
    max_heapify(h,1);
    return max;
}


void Heap_Increase_Key(Heap h,int i,int key){
    if(key < h->A[i]->key){
        fprintf(stderr,"new key is smaller than current key\n");
    }
    h->A[i]->key = key;
    while (i > 1 && h->A[parent(i)]->key < h->A[i]->key){
        swapHeap(h,i,parent(i));
        i = parent(i);
    }
}

void Max_Heap_Insert(Heap h,int key,void* data){
    h->size++;
    /*if(h->size >= h->length){
         Heap copy = copyHeap(h);
         freeHeap(&h);
         h = malloc(sizeof(HeapSortObj));
         h->A = malloc(sizeof(HeapNode) * (copy->size*2) );
         h->length = copy->size*2;
         h->size = t;
         for(int i =1;i<= copy->size;i++){
            h->A[i] = copy->A[i];
        }
        freeHeap(&copy);
    }*/
    if(h->A == NULL){
        if(h->length == 0){
            h->length = 10;
        }
        h->A = malloc(sizeof(HeapNode)*h->length);
        for(int i=1; i < h->length;i++){
            HeapNode* n = malloc(sizeof(HeapNode));
            n->key = 0;
            n->data = NULL;
            h->A[i] = n;
        }
    }
    if(h->size >= h->length){
        h->A = realloc(h->A,sizeof(HeapNode) * (h->length * 2) );
        h->length = h->size * 2;
        for(int i = h->size; i < h->length;i++){
            HeapNode* n = malloc(sizeof(HeapNode));
            n->key = 0;
            n->data = NULL;
            h->A[i] = n;
        }
    }

    h->A[h->size]->key = INT_MIN;
    h->A[h->size]->data = data;
    Heap_Increase_Key(h,h->size,key);
}   
// Min Heap Sort ------------------------------------------------------
void min_heapify(Heap h,int i){
    int l = left(i);
    int r = right(i);
    int smallest = 0;
    if (l <= h->size && h->A[l]->key < h->A[i]->key ){
        smallest = l;
    }
    else{
        smallest = i;
    }

    if (r <= h->size && h->A[r]->key < h->A[smallest]->key ){
        smallest = r;
    }
    if (smallest != i){
        swapHeap(h,smallest,i);
        min_heapify(h,smallest);
    }
}
void build_min_heap(Heap h){
	h->size = h->length;
    for (int i = h->length/2;i >=1; i--){
        min_heapify(h,i);
    }
}
// Min priority queue ----------------------------------------------------

HeapNode* Heap_Minimum(Heap h){
    if(h != NULL && h->size != 0){
        return h->A[1];
    }
    else{
        fprintf(stderr,"Heap == NULL || size == 0 \n");
        exit(EXIT_FAILURE);
    }
}
HeapNode* Heap_Extract_Min(Heap h){
    if(h->size < 1){
        fprintf(stderr,"heap underflow\n");
        exit(EXIT_FAILURE);
    }
    HeapNode* min = h->A[1];
    h->A[1] = h->A[h->size];
    h->size--;
    min_heapify(h,1);
    return min;
}


void Heap_Decrease_Key(Heap h,int i,int key){
    if(key > h->A[i]->key){
        fprintf(stderr,"new key is larger than current key\n");
    }
    h->A[i]->key = key;
    while (i > 1 && h->A[parent(i)]->key > h->A[i]->key){
        swapHeap(h,i,parent(i));
        i = parent(i);
    }
}

void Min_Heap_Insert(Heap h,int key,void* data){
    h->size++;
    if(h->A == NULL){
        if(h->length == 0){
            h->length = 10;
        }
        h->A = malloc(sizeof(HeapNode)*h->length);
        for(int i=1; i < h->length;i++){
            HeapNode* n = malloc(sizeof(HeapNode));
            n->key = 0;
            n->data = NULL;
            h->A[i] = n;
        }
    }
    if(h->size >= h->length){
        h->A = realloc(h->A,sizeof(HeapNode) * (h->length * 2) );
        h->length = h->size * 2;
        for(int i = h->size; i < h->length;i++){
            HeapNode* n = malloc(sizeof(HeapNode));
            n->key = 0;
            n->data = NULL;
            h->A[i] = n;
        }
    }
    h->A[h->size]->key = INT_MAX;
    h->A[h->size]->data = data;
    Heap_Decrease_Key(h,h->size,key);
}
int HeapMaxDepth(Heap h,int i){
    if(i > h->length){return 0;}
    else{
        int lDepth = HeapMaxDepth(h,left(i));   
        int rDepth = HeapMaxDepth(h,right(i));   
        if(lDepth > rDepth){
            return(lDepth+1);
         }
        else{
        return(rDepth+1);
     }
    }
}
