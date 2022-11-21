#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 3

struct stack{
int a[size];
int top;
};

void push(struct stack *p){
    int n;
    if(p->top>size-1){
        printf("stack overflow\n");
        return;
    }
    else{
        p->top++;
        printf("enter the number to push\n");
        scanf("%d",&n);
        p->a[p->top]=n;
    }
};
int pop(struct stack *p){
    int n;
    if(p->top==-1){
        printf("stack underflow\n");
        exit(0);
    }
    else{
        n=p->a[p->top];
        p->top--;
        return(n);
    }

};
void display(struct stack *p){
    if(p->top==-1){
        printf("empty stack\n");
        return;
    }
    else{
        for(int i=p->top;i>-1;i--){
            printf("%d\n",p->a[i]);
        }
    }
};

int main(){
struct stack st;
st.top=-1;
int d;
while(1){
    printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
    int ch;
    scanf("%d",&ch);
    switch(ch){
        case(1):push(&st);
                break;
        case(2):d=pop(&st);
                printf("popped element: %d\n",d);
                break;
        case(3):display(&st);
                break;
        case(4):exit(0);
                break;
        default:exit(0);
                break;
    }
}
return 0;
}
