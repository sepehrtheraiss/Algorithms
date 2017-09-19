#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HeapSort.h"

    typedef struct HuffNode{
        char c;
        HeapNode* left;
        HeapNode* right;
    } HuffNode;
// replaces the identical match of char with $ for efficiency
// returns the frequency of a character in the given string
int freq(char c,char* str,int strlen){
    int n = 0;
    for(int i=0;i<strlen;i++){
        if(c == str[i]){
            n++;
            str[i] = '$';
        }
    }
return n;
}
// maps each frequency of the character 
void mapFreq(char* C,int strlen,List l){
    char Ccopy[strlen];
    strcpy(Ccopy,C);
    printf("%s\n",Ccopy);
    for(int i=0;i<strlen;i++){
        if(Ccopy[i] != '$'){
            HeapNode* n = malloc(sizeof(HeapNode));
            n->data = malloc(sizeof(HuffNode));
            ((HuffNode *)n->data)->c     = Ccopy[i];
            ((HuffNode *)n->data)->left  = NULL;
            ((HuffNode *)n->data)->right = NULL;
            n->key = freq(Ccopy[i],Ccopy,strlen);
            append(l,n);
        }
    }
}
int main()
{
    List l = newList();
    char* C = "One of the theories of mystery spot is said to be caused by natural hallucinations gas, Welcome to Santa Cruz!"; 
    int n = strlen(C);
    mapFreq(C,n,l);
    Heap h = newHeap(l);
    build_min_heap(h);
    printHeap(stdout,h,'c');
    for(int i =1;i>1;i++){
        HuffNode* z  = malloc(sizeof(HuffNode));       
        z->left  = Heap_Extract_Min(h);
        z->right = Heap_Extract_Min(h);
        Min_Heap_Insert(h,z->left->key+z->right->key,z);
    }
    printf("%i\n",Heap_Maximum(h)->key);
    freeList(&l);
    freeHeap(&h);
    return 0;
}
