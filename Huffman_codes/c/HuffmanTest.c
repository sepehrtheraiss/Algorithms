#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HeapSort.h"

    typedef struct HuffNode{
        char c;
        int code;
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
int asciiInt(char c){
    int i = (int)c;
    // 0-9
    if( i >= 48 && i <=57){
        return i-48;
    }
    // A-Z
    else if(i >= 65 && i <= 90){
        return i-55;
    }
    // a-z
    else if(i >= 97 && i <=122){
        return i-61;
    }
    else{
        printf("Invalid character %c\n",c);
        return -1;
    }
}
// will traverse inorder and assign 0 for going left and 1 for right to the character
void inorder(HuffNode* n,int* i,int* A){
    if(n!=NULL){
        if(n->left != NULL){
            (*i) *=2;
            inorder((HuffNode*)n->left->data,i,A);
        }
        if(n->right != NULL){
            (*i) = ((*i)*2) + 1;
            inorder((HuffNode*)n->right->data,i,A);
        }
        if(n->left == NULL && n->right == NULL){
            A[asciiInt(n->c)] = *i;
            n->code = *i;
            printf("c: %c i:%i\n",n->c,*i);
        }
        (*i) /=2; // traversing up the tree
    }
}
void encode(char* str,int strLength,int* A,List codes){
    for(int i =0;i<strLength;i++){
        printf("%c\n",str[i]);
        //append(codes,&A[asciiInt(str[i])]);
    }
}
/*int HuffDepth(HuffNode* n){
    if(n == NULL){
        return 0;
    }
    else{
        if(n->left != NULL && n->right != NULL){
            int lDepth = HuffDepth((HuffNode*)n->left->data);
            int rDepth = HuffDepth(n->right->data);
        }
        else{return 0;}
            if(lDepth < rDepth){
                return lDepth+1;
            }
            else{
                return rDepth+1;
            }
     }
}*/
int main()
{
    List l = newList();
    //char* C = "One of the theories of mystery spot is said to be caused by natural hallucinations gas, Welcome to Santa Cruz!"; 
    //char* C="sepehr";
    // test case from Introduction to Algorithms 3rd edition
    char* C = malloc(sizeof(100));
    for(int i = 0;i<100;i++){
        if(i <45){
            C[i] = 'a';
        }
        else if(i >= 45 && i < 58){
            C[i] = 'b';
        }
        else if(i >= 58 && i < 70){
            C[i] = 'c';
        }
        else if(i >= 70 && i < 86){
            C[i] = 'd';
        }
        else if(i >= 86 && i < 95){
            C[i] = 'e';
        }
        else{
            C[i] = 'f';
        }
    }

    int n = strlen(C);
    //for(int i =0;i<n;i++){printf("%c\n",C[i]);}
    int u = mapFreq(C,n,l);
    Heap h = newHeap(l);
    build_min_heap(h);
    printf("size: %i length: %i \n", HeapSize(h),HeapLength(h));
    printHeap(stdout,h,'c');
    printf("u:%i\n",u);
    for(int i =0;i<u-1;i++){
        HuffNode* z  = malloc(sizeof(HuffNode));       
        z->c = '$';
        z->left  = Heap_Extract_Min(h);
        z->right = Heap_Extract_Min(h);
        Min_Heap_Insert(h,z->left->key+z->right->key,z);
    }

   // printf("huff tree height: %i\n",HuffDepth((HuffNode*)Heap_Minimum(h)->data));
    printf("%i\n",Heap_Minimum(h)->key);
    //printf("%c\n",((HuffNode*)((HuffNode*)Heap_Minimum(h)->data)->left->data)->c);
    int* codes = malloc(sizeof(int)*62);
    int binary = 0;
    inorder((HuffNode*)Heap_Minimum(h)->data,&binary,codes);
    //clear(l);
    List list = newList();
    encode(C,n,codes,list);
    //printList(stdout,list,'i');
 //   printf("%i\n",Heap_Minimum(h)->key);
    freeList(&l);
    //freeList(&list);
    freeHeap(&h);
    return 0;
}
