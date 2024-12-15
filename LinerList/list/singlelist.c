#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;

typedef struct Node
{
    ElementType data;
    struct Node *next;
}Node;

Node* initList(){
    Node *head = (Node*)malloc(sizeof(Node));
    head -> data = -1;
    head -> next = NULL;
    return head;
}

void list(Node *head){
    Node *node = head -> next;
    while(node != NULL){
        printf("%d ->",node -> data);
        node = node -> next;
    }
    printf(" NULL\n");
}

void insertHead(Node *head,ElementType e){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> data = e;
    node -> next = head -> next;
    head -> next = node;
}


void insertTail(Node *head,ElementType e){
    //find the last node in siglelist
    Node *tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    Node *cur = (Node*)malloc(sizeof(Node));
    cur -> data = e;
    tail -> next = cur;
    cur -> next = NULL;
}

void insertIndex(Node *head,int pos,ElementType e){
    //find the prev Node
    Node *prev = head;
    int count = 0;
    while(count < pos - 1 && prev -> next != NULL){
        prev = prev -> next;
    }
    Node *cur = (Node*)malloc(sizeof(Node));
    cur -> data = e;
    cur -> next = prev -> next;
    prev -> next = cur;
}

void deleteIndex(Node *head,int pos){
    Node *prev = head;
    int count = 0;
    while(count < pos-1 && prev -> next != NULL){
        prev = prev -> next;
        count++;
    }
    //skip the node
    if(prev -> next != NULL){
        Node *cur = prev -> next;
        prev -> next = cur -> next;
        free(cur);
    }
}
int listLength(Node *head){
    int count = 0;
    Node *p = head;
    while(p != NULL){
        p = p -> next;
        count++;
    }
    return count;
}
void freeList(Node *head){
    Node *p = head;
    Node *q;
    while(p != NULL){
        //save the next node
        q = p -> next;
        free(p);
        p = q;
    }
    head -> next = NULL;
}
int main(int argc,char const *argv[]){
    Node *N = initList();
    insertHead(N,53);
    insertHead(N,63);
    insertHead(N,72);
    insertTail(N,62);
    insertIndex(N,0,234);
    list(N);
    deleteIndex(N,3);
    list(N);
    int length = listLength(N);
    printf("The seqlists' length is %d\n",length);
    printf("free the seqlist\n");
    freeList(N);
    list(N);
    length = listLength(N);
    printf("The seqlists' length is %d\n",length);
}