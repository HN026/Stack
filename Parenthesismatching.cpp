#include<iostream>
#include<string.h>

using namespace std;


struct Node{
    char data;
    struct Node *next;
}*top = NULL;


void push( char x)
{
    struct Node *t;
    t = new struct Node;
    if(t==NULL)
    {
        cout<<"Stack is full"<<endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}


char pop()
{
    struct Node *t;
    char x = -1;

    if(top == NULL)
    {
        cout<<"Stack is empty."<<endl;
    }
    else{
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }

    cout<<endl;
}


int isBalanced( char *exp)
{
    for(int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            if(top==NULL)
            {
                return 0;
            }
            else{
                pop();
            }
        }
    }

    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


int main()
{
    char *exp = "((a+b)*(c-d))";
    cout<<isBalanced(exp)<<endl;
}