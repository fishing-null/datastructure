#include<stdio.h>
#include<stdlib.h>
#define MAXSIEZE 100

typedef int ElementType;

typedef struct{
    ElementType *data;
    int front;
    int rear;
} CircularQueue;

CircularQueue* initQueue(){
   CircularQueue *Q = (CircularQueue*)malloc(sizeof(CircularQueue));
   Q -> front = 0;
   Q -> rear = 0;
   Q -> data = (ElementType*)malloc(sizeof(ElementType));
   return Q;
}

void offer(CircularQueue *Q,ElementType e){
    if(((Q -> rear + 1) % MAXSIEZE) == Q -> front){
        printf("Queue is full\n");
        return;
    }
    Q -> data[Q->rear] = e;
    Q -> rear = (Q -> rear + 1) %  MAXSIEZE;
}

int pop(CircularQueue *Q){
    if(Q -> front == Q -> rear){
        printf("Queue is empty\n");
        return -1;
    }
    ElementType ret = Q -> data[Q -> front];
    Q -> front = (Q -> front + 1) % MAXSIEZE; 
}

int peek(CircularQueue *Q){
    return Q -> data[Q -> front];
}

void listQueue(CircularQueue *Q){
    for(int i = Q -> front; i != Q -> rear;){
        ElementType e = Q -> data[i];
        i = (i+1) % MAXSIEZE;
        printf("%d ",e);
    }
    printf("\n");
}

int isEmpty(CircularQueue *Q){
    if((Q -> rear == Q -> front)){
        return 1;
    }
    return 0;
}
int main(int argc,char const *argv[]){
    CircularQueue *Q = initQueue();
    ElementType a,b,c;
    a = 10;
    b = 11;
    c = 14;
    int flag = isEmpty(Q);
    if (flag){
        printf("empty\n");
    }
    printf("offer %d,%d,%d\n",a,b,c);
    offer(Q,a);
    offer(Q,b);
    offer(Q,c);
    listQueue(Q);
    int num = peek(Q);
    printf("peek number:%d\n",num);
    pop(Q);
    pop(Q);
    flag = isEmpty(Q);
    if (flag){
        printf("empty\n");
    }else{
        printf("not empty\n");
    }
    listQueue(Q);

}