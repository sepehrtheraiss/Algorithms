#include<stdio.h>

// max-heapify O(lg n) maintains the max heap property
// build max heap O(n) produces a max heap from an unordered input array
// heaposort O(n lg n) sorts an array 
// max-heap-insert, heap-extract-max, heap-increase-key and heap-maximum O(lg n) implementation for priority queue

int Alength = 100;
int elements = 0;
int size(){return elements;}
int length(){return Alength;}

// returns index
// needs error checking
int parent(int* A,int i){return A[i/2];}
int left(int* A,int i){return A[2*i];}
int right(int* A,int i){return A[2*i+1];}

void max_heapify(int* A,int i){
    int l = left(A,i);
    int r = right(A,i);
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
        int tmp = A[largest];
        A[largest] = A[i];
        A[i] = tmp;
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
    for (int i = length(); i <= 2;i--){
        int tmp = A[i];
        A[i] = A[1];
        A[1] = tmp;
        elements--;
        max_heapify(A,1);
    }
}
int main()
{
    Alength = 10;
    int A [Alength];

    for (int i = 1; i <= 5;i++){
        A[i] = i*2;
        elements++;
    }
    printf("l: %i r: %i \n",left(A,2),right(A,2));
//    max_heapify(A,1);
//    build_max_heap(A);
    for (int i = 1;i<=5;i++){
    printf("%i ",A[i]);
    }
    printf("\n");
    return 0;
}
