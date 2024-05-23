#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *top;
int count=0;

void display();
void push();
void pop();

int main(){
    int ch, x;
    do{
        printf("\n1.Push\n2.Pop\n3.Display\nExit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch){
            case 1:
            printf("Enter a Number: ");
            scanf("%d", &x);
            push(x);
            break;
            case 2: pop();break;
            case 3: display();break;
        }
    }
    while(ch!=4);
}

void push(int x){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("overflow\n");
        return;
    }
    if(top==NULL){
        temp->info=x;
        temp->next=NULL;
        top=temp;
    }
    else{
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=x;
        temp->next=top;
        top=temp;
    }
    count++;
}

void pop(){
    struct node *temp;
    if(top==NULL){
        printf("Underflow\n");
        return;
    }
    else{
        temp=top;
        top=top->next;
        printf("Poped element is %d\n", temp->info);
        count--;
        free(temp);
    }
}

void display(){
    struct node *ptr;
    if(top==NULL){
        printf("Underflow\n");
        return;
    }
    else{
        printf("Stack elements are\n");
        ptr=top;
        while(ptr!=NULL){
            printf("%d ", ptr->info);
            ptr=ptr->next;
        }
    }
}