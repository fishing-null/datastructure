#include<stdio.h>
#define MAXSIZE 100

typedef int ElementType;

typedef struct 
{
    /* data */
    
    //count the elements' number of seqlist
    int length;

    // a container to store elements
    ElementType data[MAXSIZE];
} Seqlist;

void initList(Seqlist *L){
    L -> length = 0;
}
int appenElem(Seqlist *L,ElementType element){
    //append an element in the seqlist's end,return 1 if success else 0

    //first. check if the seqlist's full
    // use the length as a index to check if the seqlist's full
    if(L -> length >= MAXSIZE){
        printf("append element fail,seqlist's full");
        return 0;
    }
    //append element and increase the length
    L -> data[L -> length] = element;
    L -> length++;
    return 1;
}
int main(int argc,char const *rgv[]){
    Seqlist list;
    initList(&list);
    printf("init the seqlist,the length of the list's %d\n",list.length);
    printf("the seqlist use %zu bytes memory\n",sizeof(list));
    appenElem(&list, 567);
    printf("after append one element, the length of the list's %d\n",list.length);
    return 0;
}