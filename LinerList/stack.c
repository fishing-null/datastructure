#include<stdio.h>
#include<stdlib.h>

#define MAXSIEZE 100
//define ths stack's struct
typedef int Elementype;

typedef struct
{
    Elementype *data;
    int top;
} Stack;

Stack* initStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s -> top = -1;
    s -> data = (Elementype*)malloc(sizeof(Elementype)*MAXSIEZE);
    return s;
}

void push(Stack* S,Elementype e){
    //check the length's legal
    if(S->top >= MAXSIEZE - 1){
        printf("illegal length");
        return;
    }
    S->top += 1;
    S->data[S->top] = e;
}

Elementype pop(Stack* S){
    Elementype e;
    if(S->top < -1 || S->top >= MAXSIEZE - 1){
        printf("illegal length");
    }
    e = S -> data[S -> top];
    S -> top -= 1;
    return e;
}

Elementype getTop(Stack* S){
    Elementype e = S -> data[S -> top];
    return e;
}

void listElem(Stack *S){
    for(int i = 0;i <= S -> top;i++){
        printf("%d\t",S->data[i]);
    }
    printf("\n");
}

int main(int args,char const *argv[]){
    Stack* S = initStack();
    push(S,100);
    push(S,10);
    push(S,13);
    push(S,03);
    listElem(S);
    Elementype e = pop(S);
    printf("pop element %d\n",e);
    listElem(S);
    e = getTop(S);
    printf("top element %d\n",e);
}