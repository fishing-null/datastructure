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
    Seqlist list;
    initList(&list);

    printf("init the seqlist,the length of the list's %d\n",list.length);
    printf("the seqlist use %zu bytes memory\n",sizeof(list));
    appenElem(&list, 567);
    appenElem(&list, 67);
    appenElem(&list, 56);
    appenElem(&list, 565);
    printf("after append one element, the length of the list's %d\n",list.length);


    listElem(&list);
    printf("insert 53 in index 2\n");
    insertElem(&list,3,53);
    listElem(&list);
    deleteElem(&list, 2);
    listElem(&list);

    int n = findElem(&list,67);
    printf("%d\n",n);
    return 0;
}