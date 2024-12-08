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

int main(int argc,char const *argv){
    Node *N = initList();
    insertHead(N,53);
    insertHead(N,63);
    insertHead(N,72);
    insertTail(N,62);
    list(N);
}