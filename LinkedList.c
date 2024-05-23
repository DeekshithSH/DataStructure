#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};
struct node *start;

void insert_begin(){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Out of Memory\n");
        return;
    }
    printf("Enter a Number: ");
    scanf("%d", &newNode->info);
    if (start==NULL){
        newNode->next=NULL;
        start=newNode;
    }
    else{
        newNode->next=start;
        start=newNode;
    }
}

void insert_pos(){
    struct node *newNode, *temp;
    newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Out of Memory\n");
        return;
    }
    int pos, i;
    printf("enter the position after which new node to be inserted: ");
    scanf("%d", &pos);
    printf("Enter a Number: ");
    scanf("%d", &newNode->info);
    if(pos==0){
        newNode->next=start;
        start=newNode;
    }
    else{
        for(i=0,temp=start;i<pos-1;i++){
            temp=temp->next;
            if (temp==NULL){
                printf("Position not found\n");
                return;
            }    
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

void insert_end(){
    struct node *temp, *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Out of Memory\n");
        return;
    }
    printf("Enter a Number: ");
    scanf("%d", &newNode->info);
    if(start==NULL){
        start=newNode;
        newNode->next=NULL;
    }
    else{
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=NULL;
    }
}

void display(){
    if(start==NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp;
    temp=start;
    printf("List elements are\n");
    while(temp!=NULL){
        printf("%d\t", temp->info);
        temp=temp->next;
    }
}

void delete_begin(){
    struct node *temp;
    if (start==NULL){
        printf("List Empty\n");
        return;
    }
    temp=start;
    start=start->next;
    printf("Deleted element is %d", temp->info);
    free(temp);
}

void delete_pos(){
    if (start==NULL){
        printf("List Empty\n");
        return;
    }    
    int pos;
    struct node *temp1, *temp2;
    printf("Enter element to delete");
    scanf("%d", &pos);
    if(pos==0){
        temp1=start;
        start=start->next;
        printf("Deleted element is %d\n", temp1->info);
        free(temp1);
    }
    else{
        int i;
        temp1=start;
        for(i=0;i<pos-1;i++){
            temp2=temp1;
            temp1=temp1->next;
            if(temp1==NULL){
                printf("Possition not found\n");
                return;
            }
        }
        temp2->next=temp1->next;
        printf("Deleted element is %d\n", temp1->info);
        free(temp1);
    }
}

void delete_end(){
    struct node *temp1, *temp2;
    if(start==NULL){
        printf("List is empty\n");
    }
    else if(start->next==NULL){
        temp1=start;
        printf("Deleted element is %d", temp1->info);
        start=NULL;
        free(temp1);
    }
    else{
        temp1=start;
        while(temp1->next!=NULL){
            temp2=temp1;
            temp1=temp1->next;
        }
        printf("Deleted element is %d\n", temp1->info);
        temp2->next=NULL;
        free(temp1);
    }
}

void search(){
    if(start==NULL){
        printf("List empty");
        return;
    }
    struct node *ptr;
    int f=0, i=1, s;
    printf("Enter the element to be searched: ");
    scanf("%d", &s);
    ptr=start;
    while(ptr!=NULL){
        if(ptr->info==s){
            f=1;
            break;
        }
        ptr=ptr->next;
        i++;
    }
    if(f){
        printf("Element found at position %d\n", i);
    }
    else{
        printf("Element not found\n");
    }
}
int main(){
    int ch;
    printf("Linked List\n");
    do{
        printf("\n1.Create\n2.Display\n3.Insert at Beginging\n4.Insert at a position\n5.Insert at end\n6.Delete from Begining\n7.Delete from a Position\n8.Delete from End\n9.Search\n10.Exit\nEnter Your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: insert_end(); break;
            case 2: display();break;
            case 3: insert_begin();break;
            case 4: insert_pos();break;
            case 5: insert_end();break;
            case 6: delete_begin(); break;
            case 7: delete_pos(); break;
            case 8: delete_end(); break;
            case 9: search(); break;
            default:
            break;
        }
    }
    while(ch!=10);
    return 0;
}