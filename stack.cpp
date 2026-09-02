#include<iostream>
using namespace std;

struct stackNode{
    int data;
    stackNode* next;
};

void push(stackNode*& top,int val)
{
    stackNode* newNode=new stackNode;
    newNode->data=val;
    newNode->next=top;
    top=newNode;
}

int pop(stackNode*& top)
{
    if(top==nullptr)
    {
        cout<<"stack is empty"<<endl;
        return -1;
    }
    stackNode* temp=top;
    int popedVal=temp->data;
    top=top->next;
    delete temp;
    return popedVal;
}

void peek(stackNode* top)
{
    if(top==nullptr)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"top value is: "<<top->data<<endl;
}

void printStack(stackNode*top)
{
    stackNode* temp=top;
    while(temp!=nullptr){
        cout<<temp->data<<" , ";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}

int main()
{
     stackNode* top=nullptr;
     
     push(top,5);
     printStack(top);

     push(top,4);
     printStack(top);

     push(top,3);
     printStack(top);

     peek(top);

    int val= pop(top);
    cout<<"Poped value "<<val<<endl;

     val= pop(top);
    cout<<"Poped value "<<val<<endl;

    peek(top);

     val= pop(top);
    cout<<"Poped value "<<val<<endl;
    
    val= pop(top);
    cout<<"Poped value "<<val<<endl;

    peek(top);


}