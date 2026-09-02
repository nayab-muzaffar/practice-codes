#include<iostream>
using namespace std;

struct queueNode{
    int data;
    queueNode* next;
};

void enqueue(queueNode*& front, queueNode*&rear,int val)
{
    queueNode* newNode=new queueNode;
    newNode->data=val;
    newNode->next=nullptr;

    if(front==nullptr)
    {
        front=newNode;
        rear=newNode;
        return;
    }
    rear->next=newNode;
    rear=newNode;
}
int dequeue(queueNode*&front,queueNode*&rear)
{
    if(front==nullptr)
    {
        cout<<"queue is empty"<<endl;
        return -1;
    }
     queueNode* temp=front;
     int dequeuedVal=front->data;
     front=front->next;
     delete temp;
     if(front==nullptr)
    {
        rear=nullptr;
    }
     return dequeuedVal;

}

void peek(queueNode*front)
{
    if(front==nullptr)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<"front value is "<<front->data<<endl;
}

bool isEmptyQueue(queueNode*front)
{
 return front==nullptr;
}

void print(queueNode* front)
{
    queueNode*temp=front;
    while(temp!=nullptr){
        cout<<temp->data<<" , ";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}


int main()
{
    queueNode* front=nullptr;
    queueNode* rear=nullptr;

    if (isEmptyQueue(front)) {
    cout << "Queue khaali hai!" << endl;
} else {
    cout << "Queue mein data hai." << endl;
}

    enqueue(front,rear,10);
    enqueue(front,rear,20);
    enqueue(front,rear,30);
    print(front);

if (isEmptyQueue(front)) {
    cout << "Queue khaali hai!" << endl;
} else {
    cout << "Queue mein data hai." << endl;
}

front=nullptr;
rear=nullptr;

int val[]={1,2,3};
for(int i=0;i<3;i++)
{
    enqueue(front,rear,val[i]);
    print(front);
    cout<<val[i]<<" enqueued"<<endl;

}
 peek(front);
int deqVal=dequeue(front,rear);
cout<<deqVal<<" dequeued"<<endl;

 deqVal=dequeue(front,rear);
cout<<deqVal<<" dequeued"<<endl;

peek(front);

 deqVal=dequeue(front,rear);
cout<<deqVal<<" dequeued"<<endl;

 deqVal=dequeue(front,rear);
cout<<deqVal<<" dequeued"<<endl;

enqueue(front,rear,99);
print(front);
peek(front);
    return 0;
}