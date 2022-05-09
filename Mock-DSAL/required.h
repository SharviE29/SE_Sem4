/*
 * required.h
 *
 *  Created on: 05-May-2022
 *      Author: exam1
 */

#ifndef REQUIRED_H_
#define REQUIRED_H_

class Node
{
public:
	int data;
	//Node *next;
	Node *lchild;
	Node *rchild;

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
};
class Stack
{
private:
	int top;
	int size;
	Node **S;
public:
	Stack()
	{
		top=-1;
		size=50;
		S=new Node *[size];
	}
	Stack(int size)
	{

		top=-1;
		this->size=size;
		S=new Node *[this->size];
	}
	void push(Node *data);
	Node *pop();
	bool isEmpty();
	Node *stackTop();
};
void Stack::push(Node *data)
{
	if(top==size-1)
		return ;
	else
		top++;
	    S[top]=data;
}
Node* Stack::pop()
{
	Node *x=nullptr;
	if(top==-1)
		return nullptr;
	else
		x=S[top];
	    top--;
	return x;
}
bool Stack::isEmpty()
{
	if(top==-1)
		return true;
	return false;
}
Node* Stack::stackTop()
{
	if(isEmpty())
		return nullptr;
	else
		return S[top];
}
class Queue
{
private:
	int front;
	int rear;
	int size;
	Node **Q;

public:
	Queue()
	{
		front=rear=-1;
		size=100;
		Q=new Node*[size];
	}
	Queue(int size)
	{
		front=rear=-1;
		this->size=size;
		Q=new Node *[this->size];
	}
	void enqueue(Node *);
	Node *dequeue();
	bool isEmpty();
};
void Queue::enqueue(Node *data)
{
	if(rear==size-1)
		return ;
	else
		rear++;
	    Q[rear]=data;
}
Node *Queue::dequeue()
{
	Node *x;
	if(rear==front)
	  return nullptr;
	else
		x=Q[front];
	    front++;
	    return x;
}
bool Queue::isEmpty()
{
	if(front==rear)
	   return true;
	return false;
}
#endif /* REQUIRED_H_ */
