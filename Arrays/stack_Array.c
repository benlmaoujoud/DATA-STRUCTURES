#include <stdio.h>
#include <stdbool.h>
#define MAX 6

int st[MAX] , top = -1 ;

void push(int st[] , int val);
int  pop(int st []) ;
int  peek(int st[]);
void printStack(int st[]);
bool isEmpty(int st[]);
bool isFull(int st[]);

int main() {
   int val , option ;

    do {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("\n Enter the number to be pushed on stack: ");
                scanf("%d", &val);
                push(st, val);
                break;
            case 2:
                val = pop(st);
                if(val != -1)
                    printf("\n The value deleted from stack is: %d", val);
                break;
            case 3:
                val = peek(st);
                printf("\n Enter the number to be pushed on stack: ");
                scanf("%d", &val);
                push(st, val);
                break;
                if(val != -1)
                    printf("\n The value stored at top of stack is: %d", val);
                break;
            case 4:
                printStack(st);
                break; }

    }while(option != 5);
    return 0;
}

bool isEmpty(int  st[]){
    return top == -1;
}

bool isFull(int st[]){
    return top == MAX - 1 ;
}

void push(int st[] , int val){
    if (isFull(st))
        printf("OVERFLOW");
    else{
        top++;
        st[top] = val;
    }
}

int pop(int st[]){
    int val ;
    if(isEmpty(st)){
        printf("UNDERFLOW");
        return -1;
    }

    else{
        val = st[top];
        top--;
    }
return val;
}


int peek(int st[]){
    int val ;
    if(isEmpty(st)){
        printf("Stack is Empty !");
        return -1;
    }
    else
        return st[top];
}

void printStack(int st[]){
    if(isEmpty(st))
    {
        printf("Stack is Empty");
        return;
    }
    else{
        for(int i = top ; i > -1 ; --i){
            printf("|----------%d---------|\n",st[i]);
        }
    }
}

