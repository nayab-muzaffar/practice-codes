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

void insertAtPosition(node*& head,int value,int position)
{
    if(position==0)
    {
        insertAtBeginning(head,value);
        return;
    }

    node* newNode=new node;
    newNode->data=value;

    node* temp=head;
    for(int i=0;i<position-1;i++)
    {
        if(temp==nullptr)
        {
           cout<<"invalid position"<<endl;
           delete newNode;
           return;
        }
        temp=temp->next;
    }
      if(temp==nullptr)
        {
           cout<<"invalid position";
           delete newNode;
           return;
        }

    newNode->next=temp->next;
    temp->next=newNode;
}

//search fun
bool search(node* head,int value)
{
    node* temp=head;
    int position=0;

    while(temp!=nullptr)
    {
        if(temp->data==value){
            cout<<"Value "<<value<<" found at position "<<position<<endl;
            return true;
        }
        temp=temp->next;
        position++;
    }
    cout<<"Value not found!"<<endl;
    return false;
}

//delete
void deleteAtBegining(node*& head)
{
    if(head==nullptr)
    {
        cout<<"list is empty";
        return;
    }

    node* temp=head;
    head=head->next;
    delete temp;
    cout<<"head deleted";
}

//del at end
 void deleteAtEnd(node*& head)
 {
    if(head==nullptr){
        cout<<"list is empty";
        return;
    }
    //edge case
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
    }

    node* temp=head;
    while(temp->next->next!=nullptr)
    {
        temp=temp->next;
    }

    delete temp->next;
    temp->next=nullptr;
    cout<<endl;
    cout<<"last node deleted"<<endl;;

 }

//del at any position
void deleteAnyValue(node*& head,int value)
{
    if(head==nullptr){
        cout<<"list is empty";
        return;
    }

    if(head->data==value){
        deleteAtBegining(head);
        return;
    }

    node* temp=head;
    while(temp->next!=nullptr && temp->next->data!=value){
        temp=temp->next;
    }

    if(temp->next==nullptr)
    {
        cout<<"value not found";
        return;
    }

    node* toDelete =temp->next;
    temp->next=temp->next->next;
    delete toDelete;
    cout<<value<<" value deleted";

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
    cout<<"inserting in linklist: "<<endl;
    insertAtBeginning(head,0);
    insertAtBeginning(head,2);
    insertAtBeginning(head,4);
    insertAtBeginning(head,6);
    printList(head);

    cout<<"Insert at diffrent position: "<<endl;
    
    insertAtPosition(head,93,1);
    cout<<"after insert: ";
    printList(head);

    insertAtPosition(head,67,5);
    cout<<"after insert: ";
    printList(head);

    
    insertAtPosition(head,44,8);
    cout<<"after insert: ";
    printList(head);


 search(head,8);
 search(head,0);
 search(head,67);


deleteAtBegining(head);
deleteAtEnd(head);
printList(head);

deleteAnyValue(head,99);
deleteAnyValue(head,2);

    cout<<endl;      
}
 