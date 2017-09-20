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
// maps each frequency of the character and returns the number of uniqe characters
int mapFreq(char* C,int strlen,List l){
    char Ccopy[strlen];
    strcpy(Ccopy,C);
    printf("%s\n",Ccopy);
    int u = 0;
    for(int i=0;i<strlen;i++){
        if(Ccopy[i] != '$'){
            HeapNode* n = malloc(sizeof(HeapNode));
            n->data = malloc(sizeof(HuffNode));
            ((HuffNode *)n->data)->c     = Ccopy[i];
            ((HuffNode *)n->data)->left  = NULL;
            ((HuffNode *)n->data)->right = NULL;
            n->key = freq(Ccopy[i],Ccopy,strlen);
            append(l,n);
            u++;
        }
    }
    return u;
}
// will traverse inorder and assign 0 for going left and 1 for right to the character
void inorder(HuffNode* node){
    inorder_decoding(node->left);
    printf("%c\n",node->c);
    inorder_decoding(node->right);
}
int main()
{
    List l = newList();
    char* C = "One of the theories of mystery spot is said to be caused by natural hallucinations gas, Welcome to Santa Cruz!"; 
    int n = strlen(C);
    int u = mapFreq(C,n,l);
    Heap h = newHeap(l);
    build_min_heap(h);
    printHeap(stdout,h,'c');
    for(int i =0;i<u-1;i++){
        HuffNode* z  = malloc(sizeof(HuffNode));       
        z->left  = Heap_Extract_Min(h);
        z->right = Heap_Extract_Min(h);
        Min_Heap_Insert(h,z->left->key+z->right->key,z);
    }
    //printHeap(stdout,h,'c');
    typedef struct node{
        char c;
        int code;
    }node;
//    node* decode = malloc(sizeof(node)*u);
    printf("max tree depth: %i\n",HeapMaxDepth(h,1));
    inorder(Heap_Minimum(h));
    freeList(&l);
    freeHeap(&h);
    return 0;
}
