#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data ;
    struct node *next;
}node;


node *push(node *top , int val);
node *pop(node *top ) ;
int   peek(node *top );
void printStack(node *top );

node  *top = NULL;

int main() {

    int val , option,x ;

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
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                if(top != NULL)
                    printf("\n The value stored at top of stack is deleted   ");
                break;
            case 3:
                val = peek(top);
                if(val != -1)
                    printf("\n The value stored at top of stack is: %d", val);
                else
                    printf("\n The Stack is Empty");

                break;
            case 4:
                printStack(top);
                break;
        }

    }while(option != 5);
    return 0;
}



node *push(node *top, int val){
    node *tmp  = (node*) malloc(sizeof(node));
    tmp->data = val ;
    if(top == NULL){
        top  = tmp ;
        top->next = NULL ;
    } else{
        tmp->next = top ;
        top = tmp ;
    }

    return top ;
}

node *pop(node *top){
    int val;
    node *tmp ;
    if(top == NULL){
        printf("UNDERFLOW");
        return NULL;
    }

    else{
        val = top->data ;
        top = top->next;

    }
    return top ;
}

int peek(node *top){

    if(top == NULL){
        printf("Stack is Empty !");
        return -1;
    }
    else
        return top->data;
}

void printStack(node *top){
    node *p ;
    if(top == NULL)
    {
        printf("Stack is Empty");
        return;
    }
    else{
        p = top ;
        while(p){
            printf("|----------%d---------|\n",p->data);
            p = p->next;
        }
    }
}

