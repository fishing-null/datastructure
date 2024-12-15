#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct Stack{
    ElementType data;
    struct Stack *next;
} Stack;

Stack* initStack(){
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S -> data = -1;
    S -> next = NULL;
    return S;
}

int isEmpty(Stack* S){
    if(S -> next == NULL){
        return 1;
    }
    return 0;
}

void push(Stack* S,ElementType e){
   Stack *cur = (Stack*)malloc(sizeof(Stack));
   cur -> data = e;
   cur -> next = S -> next;
   S -> next = cur;
}

ElementType pop(Stack* S){
    Stack *cur = S -> next;
    if(cur != NULL){
        ElementType e = cur -> data;
        S -> next = cur -> next;
        free(cur);
        return e;
    }
    return NULL;
}

ElementType getTop(Stack* S){
    Stack *cur = S -> next;
    return cur -> data;
}

void list(Stack* S){
    Stack *cur = S -> next;
    while(cur != NULL){
        printf("%d->",cur->data);
        cur = cur -> next;
    }
    printf("NULL\n");
}

int main(int argc,char const *argv[]){
    Stack *S = initStack();
    int flag = isEmpty(S);
    printf("%d\n",flag);
    push(S,100);
    push(S,1920);
    push(S,120);
    push(S,192);
    list(S);
    int num = pop(S);
    printf("pop num:%d\n",num);
    list(S);
}