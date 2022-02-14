#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;

    public:
    Node()
    {
        data=0;
        lchild=rchild=nullptr;
    }
    Node(int data)
    {
        this->data=data;
        lchild=rchild=nullptr;
    }
    
    friend class Queue;
};
class Queue
{
    private:
    int front;
    int rear;
    int size;
  Node **Q;

    public:
    Queue();
    Queue(int x);
    void enqueue(Node *x);
    Node *dequeue();
    int sizeofqueue();
    bool isEmpty();
};
Queue::Queue()
{
    front=rear=-1;
    size=0;
    Q=new Node *[size];
}
Queue::Queue(int size)
{
    front=rear=-1;
    this->size=size;
    Q=new Node *[this->size];
}
void Queue::enqueue(Node *x)
{
    if(rear==size-1)
        cout<<"full";
    else
    {
        rear++;
        Q[rear]=x;
    }  
}
Node *Queue::dequeue()
{
    Node *x=nullptr;
    if(front==rear)
        cout<<"empty";
    else
    {
        x=Q[front+1];
        front++;
    }   
    return x;
}
bool Queue::isEmpty()
{
    if(front==rear)
        return true;
    return false;  
}
int Queue::sizeofqueue()
{
    return (front-rear);
}
class Stack
{
    private:
    int size;
    int top;
    Node **S;
    public:
    Stack();
    Stack(int size);
    void push(Node *x);
    Node *pop();
    bool isFull();
    bool isEmpty();
    Node *stackTop();
};
Stack::Stack()
{
    int size=50;
    top=-1;
    S=new Node *[size];
}
Stack::Stack(int size)
{
    this->size=size;
    top=-1;
    S=new Node *[size];
}
void Stack::push(Node *x)
{
    if(isFull())
    {
        cout<<"Stack overflow";
    }
    else
    {
        top++;
        S[top]=x;
    }
}
Node *Stack::pop()
{
    Node *x=nullptr;
    if(isEmpty())
    {
        cout<<"Stack underflow";
    }
    else
    {
        x=S[top];
        top--;
    }
    return x;
}
bool Stack::isFull()
{
    if(top==size-1)
        return true;
    return false;   
}
bool Stack::isEmpty()
{
    if(top==-1)
        return true;
    return false;   
}
Node *Stack::stackTop()
{
    if(isEmpty())
        return nullptr;
    else
        return S[top];   
}
