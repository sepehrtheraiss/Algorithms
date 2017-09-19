#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HeapSort.h"

// retuns the lengths of the string plus the number of unique characters
/*int strlenNunique(char* C,int unique){
    char* ptr = C;
    int len = 0;
    while(*ptr!='\0'){
        len++;
    }
}*/
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
    for(int i=0;i<strlen;i++){
        if(Ccopy[i] != '$'){
            HeapNode* n = malloc(sizeof(HeapNode));
            n->key = freq(Ccopy[i],Ccopy,strlen);
            n->data = &Ccopy[i];
            append(l,n);
        }
    }
}
int main()
{
    typedef struct node{
        void* huffNode;
        int left;
        int right;
    } node;
    List l = newList();
    char* C = "are mamaman jan bokonam onjaro ay khoda"; 
    int n = strlen(C);
    mapFreq(C,n,l);
    Heap h = newHeap(l);
    build_min_heap(h);
    printHeap(stdout,h,'s');
    // for(int i =0;i<n;i++){
    //     node* z = malloc(sizeof(node));       
    //     z->left = 
    // }

    freeList(&l);
    freeHeap(&h);
    return 0;
}
