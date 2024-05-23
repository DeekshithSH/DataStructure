#include<stdio.h>

#define maxsize 5

int queue[maxsize];
int front=-1, rear=-1;

void display();
void enQueue();
void deQueue();

int main(){
    int ch;
    do{
        printf("\n1.Insert an Element\n2.Delete an Element\n3.Display Queue\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch){
            case 1: enQueue(); break;
            case 2: deQueue(); break;
            case 3: display(); break;
        }
    }
    while(ch!=4);
    return 0;
}

void enQueue(){
    if(rear>=maxsize-1){
        printf("Overflow");
        return;
    }
    int x;
    printf("Enter a  Element: ");
    scanf("%d", &x);
    if(rear==-1 && front==-1){
        front=0;
        rear=0;
    }
    else{
        rear=rear+1;
    }
    queue[rear]=x;
}

void deQueue(){
    int item;
    if(front==-1 || front>rear){
        printf("Stack Underflow");
        return;
    }
    else{
        item=queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
        printf("Removed element is %d", item);
    }
}

void display(){
    if(rear==-1){
        printf("Underflow");
        return;
    }
    printf("Queue elements are \n");
    for(int i=front;i<=rear;i++){
        printf("%d ", queue[i]);
    }
}