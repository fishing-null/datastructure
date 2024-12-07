#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;

typedef struct
{
    ElementType data;
    struct Node *next;
}Node;

Node initList(){
    Node head = (Node*)malloc(sizeof(Node));
    head -> data = -1;
    head -> next = NULL;
    return head;
}

void list(Node *head){
    Node node = head -> next;
    while(node != NULL){
        printf("%d ->",node -> data);
    }
    printf("\n");
}
void insertHead(Node *head,ElementType e){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> data = e;
    node -> next = head -> next;
    head -> next = node;
}



int main(int argc,char const *argv){

}