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

    friend class Stack;
};
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