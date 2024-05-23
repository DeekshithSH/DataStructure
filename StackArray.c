#include<stdio.h>
#include<stdlib.h>
int stack[50], n, choice, top=-1, x, i;
void push(){
    if(top>=n-1){
        printf("Stack Overflow\n");
    }
    else{
        printf("Enter a Number: ");
        scanf("%d", &x);
        top++;
        stack[top]=x;
    }
}

void pop(){
    if(top<=-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Poped element is %d\n", stack[top]);
        top--;
    }
}

void display(){
    if (top<=-1){
        printf("Stack Empty\n");
    }
    else{
        printf("Stack Elements are\n");
        for(i=0;i<=n-1;i++){
            printf("%d\t", stack[i]);
        }
    }
}

int main(){
    printf("Stack using Array\n");
    printf("Enter stack size");
    scanf("%d", &n);
    do{
        printf("\n1. PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nEnter Your Choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            default: printf("Invalid Choice\n");
        }
    }
    while(choice!=4);
    return 0;
}