#include<stdio.h>
#include<stdlib.h>

struct Treenode;
typedef struct Treenode *Searchtree ;

struct Treenode{
    int Element;
    struct Treenode *left;
    struct Treenode *right;
};

Searchtree T;

Searchtree insert(int, Searchtree);
void display(Searchtree, int);
void inorder(Searchtree);
void preorder(Searchtree);
void postorder(Searchtree);

int main(){
    T=NULL;
    int ch, x;
    do{
        printf("\n1.Insert\n2.Display\n3.Inorder\n4.PreOrder\n5.PostOrder\n6.Exit");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch){
            case 1:
            printf("Enter Number to Insert: ");
            scanf("%d", &x);
            T=insert(x, T);
            break;;
            case 2: display(T, 1);
            break;
            case 3: printf("In Order Traversal\n");
            inorder(T);
            break;
            case 4: printf("Preorder Traversal\n");
            preorder(T);
            break;
            case 5: printf("Postorder Traversal\n");
            postorder(T);
            break;
            default: printf("Invalid Input");
            break;
        }
    }
    while(ch!=6);
}

Searchtree insert(int x, Searchtree T){
    if (T==NULL){
        T=(Searchtree)malloc(sizeof(struct Treenode));
        T->Element=x;
        T->left=T->right=NULL;
    }
    else if(x<=T->Element){
        T->left=insert(x, T->left);
    }
    else if(x>T->Element){
        T->right=insert(x, T->right);
    }
    return T;
}

void display(Searchtree T1, int level){
    if(T1!=NULL){
        display(T1->left, level+1);
        if(T1==T)
        printf("Root-> ");
        else{
            for(int i=0;i<level;i++){
                printf(" ");
            }
        }
        printf("%d\n ", T1->Element);
        display(T1->right, level+1);
    }
}

void inorder(Searchtree T1){
    if(T1!=NULL){
        inorder(T1->left);
        printf("%d ", T1->Element);
        inorder(T1->right);
    }
}

void preorder(Searchtree T1){
    if(T1!=NULL){
        printf("%d ", T1->Element);
        preorder(T1->left);
        preorder(T1->right);
    }
}

void postorder(Searchtree T1){
    if(T1!=NULL){
        postorder(T1->left);
        postorder(T1->right);
        printf("%d ", T1->Element);
    }
}