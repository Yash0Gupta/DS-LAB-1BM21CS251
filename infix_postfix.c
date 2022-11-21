#include<stdio.h>
#include<math.h>
char infix[20],postfix[20],stack[20],symbol,temp;
int top=-1,pos=0,index=0,length;

void push(char symbol){
top++;
stack[top]=symbol;
}

char pop(){
char temp=stack[top--];
return temp;
}

int pred(char symbol){
    int p;
switch(symbol){
    case('^'):
        p=2;
        break;
    case('*'):
    case('/'):
        p=1;
        break;
    case('+'):
    case('-'):
        p=0;
        break;
    case('('):
        p=-1;
        break;
    case('#'):
        p=-2;
        break;
    }
    return p;
}

void infix_postfix()
{
    length=strlen(infix);
    push('#');
    while(index<length){
        symbol=infix[index];
        switch(symbol){
        case('('):
            push(symbol);
            break;
        case(')'):
            temp=pop();
            while(temp!='('){
                    postfix[pos++]=temp;
                    temp=pop();
                  }
            break;
        case('+'):
        case('-'):
        case('*'):
        case('/'):
        case('^'):
            while(pred(stack[top])>pred(symbol)){
                temp=pop();
                postfix[pos++]=temp;
            }
            push(symbol);
            break;
        default:
            postfix[pos++]=symbol;
            break;
        }
        index++;
    }
    while(top>0){
        temp=pop();
        postfix[pos++]=temp;
    }
}
int main(){
    printf("enter the infix expression\n");
    scanf("%s",infix);
    infix_postfix();
    printf("the infix expression is: %s\n",infix);
    printf("the postfix expression is: %s\n",postfix);
    return 0;
}
