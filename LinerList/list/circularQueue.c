#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct Node{
    ElementType data;
    struct Node *next;
}Node;

typedef struct Queue{
    // 通过头指针和尾指针来保存队头和队尾的位置
    Node *front;
    Node *rear;
}Queue;

Queue* init(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    Node *head = (Node *)malloc(sizeof(Node));
    head -> next = NULL;
    q -> front = head;
    q -> rear = head;
    return q;
}

void eQueue(Queue *q,ElementType e){
    // 通过尾插的方式入队
    Node *cur = (Node *)malloc(sizeof(Node));
    cur -> data = e;
    cur -> next = NULL;
    // 将新的节点插入到rear的后面
    q -> rear -> next = cur;
    // 更新尾指针的位置
    q -> rear = cur;
}

void dQueue(Queue *q){
    // 通过头删的方式出队
    Node *cur = q -> front -> next;
    // 让头节点指向下一个节点
    q -> front -> next = cur -> next;
    // 如果出队的是最后一个节点，需要更新rear
    if(cur == q -> rear){
        q -> rear = q -> front;
    }
    // 从内存中释放cur
    free(cur);
}

void listQueue(Queue *q){
    Node *cur = q -> front -> next;
    while(cur != q -> rear){
        printf("%d -> ",cur -> data);
        cur = cur -> next;
    }
    printf("%d -> NULL\n",cur -> data);
}

int isEmpty(Queue *q){
    return q -> front == q -> rear;
}

ElementType peek(Queue *q){
    if(isEmpty(q)){
        printf("The queue is empty\n");
        return -1;
    }
    return q -> front -> next -> data;
}

int main(int argc,char const *argv[]){
    Queue *q = init();
    eQueue(q,10);
    eQueue(q,20);
    eQueue(q,30);
    eQueue(q,40);
    eQueue(q,50);
    listQueue(q);
    dQueue(q);
    listQueue(q);
    printf("peek: %d\n",peek(q));
    return 1;
}