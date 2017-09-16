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
// maps each frequency of character to it's alphabet
void mapFreq(char* C,int strlen,List CfreqList,List uniqueChars){
    char Ccopy[strlen];
    strcpy(Ccopy,C);
    
    for(int i=0;i<strlen;i++){
        if(Ccopy[i] != '$'){
            append(uniqueChars,Ccopy[i]);
            append(CfreqList,freq(Ccopy[i],Ccopy,strlen));
        }
    }
}
int main()
{
    typedef struct node{
        int freq;
        int left;
        int right;
    } node;
    List freqList = newList();
    List uniqueList = newList();
    char* C = "are mamaman jan bokonam onjaro ay khoda"; 
    int n = strlen(C);
    mapFreq(C,n,freqList,uniqueList);
    printList(stdout,freqList);
    printList(stdout,uniqueList);
    freeList(&freqList);
    freeList(&uniqueList);
    return 0;
}
