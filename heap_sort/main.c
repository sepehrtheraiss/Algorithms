#include<stdio.h>
#include<stdlib.h>

// max-heapify O(lg n) maintains the max heap property
// build max heap O(n) produces a max heap from an unordered input array
// heaposort O(n lg n) sorts an array 
// max-heap-insert, heap-extract-max, heap-increase-key and heap-maximum O(lg n) implementation for priority queue

int Alength = 100;
int elements = 0;
int size(){return elements;}
int length(){return Alength;}
void swap(int* A,int i,int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
// returns index
// needs error checking
int parent(int i){return i/2;}
int left(int i){return (i << 1);}
int right(int i){return ((i << 1) | 1);};

void max_heapify(int* A,int i){
    int l = left(i);
    int r = right(i);
    int largest = 0;
    if (l <= size() && A[l] > A[i]){
        largest = l;
    }
    else{
        largest = i;
    }

    if (r <= size() && A[r] > A[largest]){
        largest = r;
    }
    if (largest != i){
        swap(A,largest,i);
        max_heapify(A,largest);
    }
}

void build_max_heap(int* A){
    elements = length();
    for (int i = length()/2;i >=1; i--){
        max_heapify(A,i);
    }
}

void heap_sort(int* A){
    build_max_heap(A);
    for (int i = length(); i >= 2;i--){
        swap(A,1,i);
        elements--;
        max_heapify(A,1);
    }
}
void print(int *A){
    printf("A: ");
    for (int i = 1; i <= length(); i++){
        printf("%i  ",A[i]);
    }
    printf("\n");
}
int main()
{
    Alength = 10;
    elements = 10;
   // int A [Alength];
   int A[] = {-1,4,1,3,2,16,9,10,14,8,7};

/*    for (int i = 1; i <= 5;i++){
        A[i] = i*2;
        elements++;
      }*/
//      printf("size(): %i\n",size());
    //printf("l: %i r: %i \n",left(A,2),right(A,2));
//    max_heapify(A,1);
//    build_max_heap(A);
    heap_sort(A);
    print(A);

/*  test case 
        for (int i = 1;i<=size();i++){
        printf("index: %i\n",i);
        printf("parrent: %i\n",parent(i));
        printf("left: %i\n",left(i));
        printf("right: %i\n",right(i));
    }*/
    return 0;
}
