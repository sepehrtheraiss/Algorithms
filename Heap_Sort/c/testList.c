
#include "List.h"

int main()
{
    List l = newList();
    append(l,1);
    append(l,2);
    append(l,3);
    append(l,4);
    int* shit = malloc(sizeof(int));
    append(l,5);
    pop(l);
    printList(stdout,l);
    freeList(&l);

    return 0;
}
