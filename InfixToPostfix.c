#include<stdio.h>
#include<ctype.h>

char stack[50];
int top=-1;

int priority(char x){
    if (x=='(')
    return 0;
    else if(x=='+' || x=='-')
    return 1;
    else if(x=='/' || x=='*')
    return 2;
}

void push(char x){
    stack[++top]=x;
}
int pop(){
    if (top==-1){
        return -1;
    }
    else{
        return stack[top--];
    }
}

int main(){
    char exp[50], *e, x;
    printf("Enter Infix Expression: ");
    scanf("%s", exp);
    e=exp;
    while(*e!='\0'){
        // printf("%c", *e);
        if(isalnum(*e)){
            printf("%c", *e);
        }
        else if(*e=='('){
            push(*e);
        }
        else if(*e==')'){
            x=pop();
            while(x!='('){
                printf("%c", x);
                x=pop();
            }
        }
        else{
            while(priority(stack[top]) >= priority(*e)){
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while(top!=-1){
        printf("%c", pop());
    }
    return 0;
}