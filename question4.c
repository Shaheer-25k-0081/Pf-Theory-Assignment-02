#include<stdio.h>
#define MAXSIZE 5

void push(int stack[], int *top, int maxSize){
    if(*top==maxSize-1){
        printf("Stack Overflow!!Can't Push More Elements\n\n");
    }
    else{
        int value;
        printf("Enter Value to Push: ");
        scanf("%d",&value);
        (*top)++;
        stack[*top]=value;
        printf("Element %d pushed Succesfully\n\n",value);
    }
}


void pop(int stack[], int *top){
    if(*top==-1){
        printf("Stack Underflow!!No Elements to be removed.\n\n");
    }
    else{
        printf("Element %d popped from the stack\n\n",stack[*top]);
        (*top)--;
    }
}


void peek(int stack[],int top){
    if(top==-1){
        printf("Nothing to Peek!!Stack is Empty\n\n");
    }
    else{
        printf("Top Element: %d\n",stack[top]);
    }
}


void display(int stack[],int top){
    if(top==-1){
        printf("Stack is Empty!!\n\n");
    }
    else{
        printf("Current Stack Elements:\n\n");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}


int main(){
    int choice,stack[MAXSIZE];
    int top=-1;
    do{
        printf("Stack Operation\n\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1: push(stack,&top,MAXSIZE);break;
            case 2: pop(stack, &top);break;
            case 3: peek(stack,top);break;
            case 4: display(stack,top);break;
            case 5: printf("Exiting Program\n");break;
            default: printf("Invalid choice!!Try Again\n");
        }
    }while(choice!=5);
    return 0;
}