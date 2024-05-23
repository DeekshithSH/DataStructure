#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *front, *rear;

void insert(int x){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Out of memory\n");
        return;
    }
    if(front==NULL){
        temp->info=x;
        temp->next=NULL;
        front=temp;
        rear=temp;
    }
    else{
        temp->info=x;
        rear->next=temp;
        rear=temp;
    }
}

void delete(){
    struct node *temp;
    if(front==NULL){
        printf("Queue Empty\n");
        return;
    }
    else{
        temp=front;
        front=front->next;
        printf("deleted value %d\n", temp->info);
        free(temp);
    }
}

void display(){
    struct node *ptr;
    if(front==NULL){
        printf("Queue Empty\n");
        return;
    }
    else{
        ptr=front;
        while(ptr!=NULL){
            printf("%d ", ptr->info);
            ptr=ptr->next;
        }
    }
}

int main(){
    int ch, x;
    do{
    printf("\n1.enQueue\n2.deQueue\n3.Display\n4.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch){
        case 1:
        printf("Enter value: ");
        scanf("%d", &x);
        insert(x);
        break;
        case 2:
        delete();
        break;
        case 3:
        display();
        break;
    }
    }
    while(ch!=4);
    return 0;
}