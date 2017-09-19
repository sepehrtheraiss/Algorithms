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
    typedef struct HuffNode{
        char c;
        char cc;
        int left;
        int right;
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
            ((HuffNode *)n->data)->cc     = 's';
            ((HuffNode *)n->data)->left  = -1;
            ((HuffNode *)n->data)->right = -1;
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
    // for(int i =0;i<n;i++){
    //     node* z = malloc(sizeof(node));       
    //     z->left = 
    // }

    freeList(&l);
    freeHeap(&h);
    return 0;
}
