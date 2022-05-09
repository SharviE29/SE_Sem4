/*
 * stacksandqueues.h
 *
 *  Created on: 28-Apr-2022
 *      Author: pict
 */

#ifndef STACKSANDQUEUES_H_
#define STACKSANDQUEUES_H_

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
    friend class Stack;
};
class Queue
{
    private:
    int front;
    int rear;
    int size;
    int *Q;

    public:
    Queue();
    Queue(int x);
    void enqueue(int x);
    int dequeue();
    int sizeofqueue();
    bool isEmpty();
};
Queue::Queue()
{
    front=rear=-1;
    size=0;
    Q=new int[size];
}
Queue::Queue(int size)
{
    front=rear=-1;
    this->size=size;
    Q=new int[this->size];
}
void Queue::enqueue(int x)
{
    if(rear==size-1)
        cout<<"full";
    else
    {
        rear++;
        Q[rear]=x;
    }
}
int Queue::dequeue()
{
    int x=0;
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
    int *S;
    public:
    Stack();
    Stack(int size);
    void push(int x);
    int pop();
    bool isFull();
    bool isEmpty();
    int stackTop();
};
Stack::Stack()
{
    int size=50;
    top=-1;
    S=new int [size];
}
Stack::Stack(int size)
{
    this->size=size;
    top=-1;
    S=new int [size];
}
void Stack::push(int x)
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
int Stack::pop()
{
   int x=0;
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
int Stack::stackTop()
{
    if(isEmpty())
        return 0;
    else
        return S[top];
}


#endif /* STACKSANDQUEUES_H_ */
