#include<stdio.h>
#define MAXSIZE 100
#include<stdlib.h>

typedef int ElementType;

typedef struct 
{
    /* data */
    
    //count the elements' number of seqlist
    int length;

    // a container to store elements
    ElementType *data;
} Seqlist;

Seqlist* initList(){
    Seqlist *L = (Seqlist*)malloc(sizeof(Seqlist));
    L -> data = (ElementType*)malloc(sizeof(ElementType)*MAXSIZE);
    L -> length = 0;
    return L;
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
void listElem(Seqlist *L){
    for(int i = 0;i < L -> length;i++){
        printf("%d\t",L->data[i]);
    }
    printf("\n");
}
void insertElem(Seqlist *L,int pos,ElementType element){
    //insert an element in seqlist
    
    //check if the pos is legal
    if(pos >= L -> length || pos < 0){
        printf("Illegal index in seqlist\n");
        return;
    }
    for(int i = L -> length;i >= pos; i--){
        //move the element behind
        L -> data[i] = L -> data[i-1];   
    }
    L -> data[pos] = element;
    L -> length += 1;
}
void deleteElem(Seqlist* L,int index){
    if(index >= L -> length || index < 0){
        printf("Illegal index in seqlist\n");
        return;
    }
    ElementType e = L->data[index];
    for(int i = index;i < L -> length - 1;i++){
        L -> data[i] = L -> data[i+1];
    }
    L -> length -= 1;
}
int findElem(Seqlist *L,ElementType e){
    for(int i = 0;i < L -> length;i++){
        if(L -> data[i] == e){
            printf("Seqlist contains element in %d index\n",i);
            return 1; 
        }
    }
    return 0;
}
int main(int argc,char const *rgv[]){
    Seqlist *list = initList();
    appenElem(list,33);
    appenElem(list,21);
    listElem(list);
    return 0;
}