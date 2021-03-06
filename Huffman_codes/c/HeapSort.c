#include "HeapSort.h"
#include <limits.h>
// strcuts ---------------------------------------------------------------------
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
        h->A[0] = NULL;

        for(int i = 1; i < h->length+1; i++){
            h->A[i] = (HeapNode *)pop(list);
          //  printf("key: %i\n",h->A[i]->key);
        }
	return h;
}

// pre: *pH != NULL , pH != NULL
void freeHeap(Heap* pH){
	if(pH != NULL && *pH != NULL){
            
                for(int i =1;i<(*pH)->length+1;i++){
                    if((*pH)->A[i] != NULL){
                        if((*pH)->A[i]->data != NULL){
                            free((*pH)->A[i]->data);
                            (*pH)->A[i]->data = NULL;
                        }
                        free((*pH)->A[i]);
                        (*pH)->A[i] = NULL;
                    }
                    
                }
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
int left(int i){return (i*2);} // i << 1 
int right(int i){return (i*2)+1;} // i << 1 | 1
void swapHeap(Heap h,int i,int j){
   HeapNode* temp =  h->A[i];
   h->A[i] = h->A[j];
   h->A[j] = temp;
}
void printHeapMemAddress(Heap h){
    printf("A memory address: \n");
    for(int i = 1; i <= h->size; i++){
        printf("%p \n",h->A[i]);
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
                fprintf(out,"key:%i data:%c\n",h->A[i]->key,*(char *)h->A[i]->data); // flaw *(*char)h->A[]->data gets the first struct var if char
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
    if(h !=NULL){
        if(h->A != NULL ){
            if(h->size > h->length){
                h->length *= 2;
                h->A = realloc(h->A,sizeof(HeapNode) * (h->length));
                printf("length increased to: %i\n",h->length);   
            }
            h->A[h->size] = malloc(sizeof(HeapNode));
            h->A[h->size]->key = INT_MIN;
            h->A[h->size]->data = data;
            Heap_Increase_Key(h,h->size,key);
            printf("Heap size incresed to: %i\n",h->size);

        }
        else{     
            fprintf(stderr,"h->A is null\n");
            exit(EXIT_FAILURE);
        }
    }
    else{
        fprintf(stderr,"h is null\n");
        exit(EXIT_FAILURE);
    }

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
    h->A[h->size] = NULL;
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
    if(h !=NULL){
        if(h->A != NULL ){
            if(h->size > h->length){
                h->length *= 2;
                h->A = realloc(h->A,sizeof(HeapNode) * (h->length));
                for(int i = h->size; i < h->length + 1;i++){
                    h->A[i] = NULL;
                }
                printf("length increased to: %i\n",h->length);   
            }
            h->A[h->size] = malloc(sizeof(HeapNode));
            h->A[h->size]->key = INT_MAX;
            h->A[h->size]->data = data;
            Heap_Decrease_Key(h,h->size,key);
            printf("Heap size incresed to: %i\n",h->size);

        }
        else{     
            fprintf(stderr,"h->A is null\n");
            exit(EXIT_FAILURE);
        }
    }
    else{
        fprintf(stderr,"h is null\n");
        exit(EXIT_FAILURE);
    }
}    

int HeapDepth(Heap h,int i){
    if(i > h->length){return 0;}
    else{
        int lDepth = HeapDepth(h,left(i));   
        int rDepth = HeapDepth(h,right(i));   
        if(lDepth > rDepth){
            return(lDepth+1);
         }
        else{
        return(rDepth+1);
     }
    }
}
