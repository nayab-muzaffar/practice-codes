#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void insertAtBeginning(node*& head, int value)
{
    node* newNode=new node;
    newNode->data=value;
    newNode->next=head;
    head=newNode;
}

void insertAtEnd(node*&head, int value)
{
    node* newNode=new node;
    newNode->data=value;
    newNode->next=nullptr;

    if(head==nullptr)
    {
        head=newNode;
        return ;
    }

    node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newNode;

}

void printList(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" , ";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}


int main()
{
    node* head=nullptr;

    cout<<"Insert at beginning:"<<endl;
    insertAtBeginning(head,0);
    printList(head);

    insertAtBeginning(head,2);
    printList(head);

    insertAtBeginning(head,4);
    printList(head);

    insertAtBeginning(head,6);
    printList(head);

    cout<<endl;
    cout<<"beginning ka reverse print hota"<<endl;
    head=nullptr;
    insertAtBeginning(head,0);
    insertAtBeginning(head,2);
    insertAtBeginning(head,4);
    insertAtBeginning(head,6);
    printList(head);


    cout<<endl;
    cout<<"Insert at end:"<<endl;
    head=nullptr;
    insertAtEnd(head,9);
    printList(head);
    
    insertAtEnd(head,7);
    printList(head);

    insertAtEnd(head,5);
    printList(head);

    insertAtEnd(head,3);
    printList(head);
    
    cout<<endl;
    cout<<"end ka forward hi print hota"<<endl;
    head=nullptr;
    insertAtEnd(head,9);
    insertAtEnd(head,7);
    insertAtEnd(head,5);
    insertAtEnd(head,3);
    printList(head);

 return 0;
}