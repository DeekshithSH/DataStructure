#include<stdio.h>
#include<stdlib.h>
typedef struct Treenode *SearchTree;
struct Treenode
{
    int Element;
    SearchTree left;
    SearchTree right;
};

SearchTree Insert(int, SearchTree);
void Display(SearchTree ,int);

SearchTree T;

int main()
{
    T=NULL;
    int ch = 1, x;
    while (ch != 3)
    {
        printf("\n1.Insert\n2.Display\n3.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            printf("Enter the element: ");
            scanf("%d", &x);
            T=Insert(x, T);
            printf("New Element is inserted");
            break;
            case 2:
            Display(T, 1);
            break;
            case 3:
            exit(0);
            break;
            default:
            printf("Invalid Choice");
            break;
        }
    }
}

SearchTree Insert(int x, SearchTree T){
    if(T==NULL){
        T=(SearchTree)malloc(sizeof(struct Treenode));
        T->Element=x;
        T->left=T->right=NULL;
    }
    else if(x<=T->Element){
        T->left=Insert(x, T->left);
    }
    else if(x>T->Element){
        T->right=Insert(x, T->right);
    }
    return T;
}

void Display(SearchTree T1, int x){
    int i;
    if(T1!=NULL){
        Display(T1->left, x+1);
        printf("\n");
        if(T1==T)
        printf("root->");
        else{
            for(i=0;i<x;i++){
                printf(" ");
            }
        }
        printf("%d", T1->Element);
        Display(T1->right, x+1);
    }
}