#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct Node
{
    ElementType data;
    struct Node *prev,*next;
}Node;

Node* initList(){
    //return a empty list
    Node* head = (Node *)malloc(sizeof(Node));
    head -> data = -1;
    head -> next = NULL;
    head -> prev = NULL;
    return head;
}

void insertHead(Node* L,ElementType e){
    //insert a node on head
    Node* cur = (Node *)malloc(sizeof(Node));
    cur -> data = e;
    cur -> next = L -> next;
    cur -> prev = L;
    if(L -> next != NULL){
        L -> next -> prev = cur;
    }
    L -> next = cur;
}

void insertTail(Node* L,ElementType e){
    //first find the tail
    Node* tail = L;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* cur = (Node *)malloc(sizeof(Node));
    cur->data = e;
    tail->next = cur;
    cur->next = NULL;
}

void insertIndex(Node* L,int pos,ElementType e){
    Node* prev = L;
    //find the prev node
    int count = 0;
    while(count < pos - 1 && prev != NULL){
        prev = prev->next;
        count++;
    }
    Node* cur = (Node *)malloc(sizeof(Node));
    cur -> data = e;
    cur -> next = prev -> next;
    cur -> prev = prev;
    //if prev->next != NULL,update the pointer
    if(prev -> next != NULL){
        prev -> next-> prev = cur;
    }
    prev -> next = cur;
}

void deleteIndex(Node* L,int pos){
    Node *prev = L;
    int count = 0;
    //find the prev node
    while(count < pos - 1){
        prev = prev->next;
        count++;
        if(prev == NULL){
            return;
        }
    }
    //ensure the deleted node is exist
    if(prev->next == NULL){
        printf("The node is not exist\n");
        return;
    }
    Node *cur = prev->next;
    prev->next = cur->next;
    cur->next->prev = prev;
    free(cur);
}

void listNode(Node* L){
    Node* cur = L -> next;
    while(cur != NULL){
        printf("%d -> ",cur->data);
        cur = cur->next;
    }
    //To the end,print NULL and \n
    printf("NULL\n");
}

int main(int argc,char const *argv[]){
    Node *L = initList();
    printf("InsertHead\n");
    insertHead(L,10);
    insertHead(L,50);
    insertHead(L,30);
    insertHead(L,140);
    insertHead(L,170);
    listNode(L);
    printf("InsertTail\n");
    insertTail(L,123);
    insertTail(L,13);
    insertTail(L,12);
    insertTail(L,23);
    listNode(L);
    insertIndex(L,9,999);
    listNode(L);
    printf("Delete index 4\n");
    deleteIndex(L,4);
    listNode(L);
}