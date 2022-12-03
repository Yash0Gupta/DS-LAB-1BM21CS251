#include<stdio.h>
#include<stdlib.h>
#define size 3
int stack[size];
int top=-1;

void push()
{
    if(top>=(size-1)){
        printf("stack overflow\n");
    }
    else{
        printf("enter the value to push\n");
        int n;
        scanf("%d",&n);
        top++;
        stack[top]=n;
    }
};
int pop()
{
    if(top==-1){
        printf("stack underflow\n");
        return;
    }
    else{
        int n;
        n=stack[top];
        top--;
        return n;
    }
};
void display(){
    if(top==-1){
        printf("empty stack\n");
        return;
    }
    else{
        for(int i=(top);i>-1;i--){
            printf("%d\n",stack[i]);
        }
    }
};

int main(){
    int choice;
    while(1){
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();
                    break;
            case 2: int del;
                    del=pop();
                    printf("popped element: %d\n",del);
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default:printf("enter a valid choice\n");
        }
    }
    return 0;
}
