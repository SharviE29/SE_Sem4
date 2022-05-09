//============================================================================
// Name        : Mock_Assignment1.cpp
// Author      : Sharvi Endait
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "required.h"
using namespace std;
class Tree
{
private:
	Node *root;

public:
	Tree()
	{
		root=nullptr;
	}
	void createTree();
	void preorderTraversal(Node* data);
	void inorderTraversal(Node* data);
	void postorderTraversal(Node* data);
	void preorderiter();
	void inorderiter();
	void postorderiter();
	int height(Node* data);
	int count (Node*);
	void mirror(Node*);
	void eraseTree(Node*);
	Node *copyTree();
	void preorderTraversal()
		{
			preorderTraversal(root);
		}
		void inorderTraversal()
			{
				inorderTraversal(root);
			}
		void postorderTraversal()
			{
				postorderTraversal(root);
			}
};

void Tree::createTree()
{
	int data;
	cout<<"Enter the value of the root node: ";
	cin>>data;
	int data1,data2;
	Node *p=new Node(data);
	Queue q(1000);
	q.enqueue(p); //contains the root node in the queue
    while(p!=nullptr || !q.isEmpty())
    {
        Node *r=q.dequeue();
    	cout<<"Enter the left child of "<<r->data<<":";
    	cin>>data1;
    	if(data1!=-1)
    	{
    		Node *t=new Node(data1);
    		r->lchild=t;
    		q.enqueue(t);
    	}
    	cout<<"Enter the right child of "<<r->data<<":";
    	    	cin>>data2;
    	    	if(data2!=-1)
    	    	{
    	    		Node *t=new Node(data2);
    	    		r->rchild=t;
    	    		q.enqueue(t);
    	    	}
    }
}
void Tree::preorderTraversal(Node *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorderTraversal(root);
		preorderTraversal(root);
	}
}
void Tree::inorderTraversal(Node *root)
{
	if(root)
	{

		inorderTraversal(root);
		cout<<root->data<<" ";
		inorderTraversal(root);
	}
}
void Tree::postorderTraversal(Node *root)
{
	if(root)
	{

		postorderTraversal(root);
		postorderTraversal(root);
		cout<<root->data<<" ";
	}
}
void Tree::preorderiter()
{
	Stack s(1000);
	Node *p=root;
	while(p!=nullptr || !s.isEmpty())
	{
		if(p!=nullptr)
		{
			cout<<p->data;
			s.push(p);
			p=p->lchild;
		}
		else
		{
			Node *p=s.pop();
			p=p->rchild;
		}
	}
}
void Tree::inorderiter()
{
	Stack s(1000);
	Node *p=root;
	while(p!=nullptr || !s.isEmpty())
	{
		if(p!=nullptr)
		{
			s.push(p);
			p=p->lchild;
		}
		else
		{
			Node *p=s.pop();
			cout<<p->data;
			p=p->rchild;
		}
	}
}
void Tree::postorderiter()
{
	Stack s1(1000),s2(1000);
	Node *p=root;
	s1.push(p);
	while(p!=nullptr || !s1.isEmpty())
	{
//		s1.push(p);
		Node *x=s1.pop();
		s2.push(x);
		if(x->lchild)
		{
			s1.push(x->lchild);
		}
		if(x->rchild)
		{
			s1.push(x->rchild);
		}
	}
	while(!s2.isEmpty())
	{
		Node *t=s2.pop();
		cout<<t->data<<" ";
	}
}
int Tree::height(Node *p)
{
	if(p)
	  return 1+ max(height(p->lchild),height(p->rchild));
}
int Tree::count(Node *p)
{
	int x=count(p->lchild);
    int y=count(p->rchild);
	return 1+x+y;
}
void Tree::mirror(Node *p)
{
	Node *temp;
	mirror(p->lchild);
	mirror(p->rchild);
	temp=p->lchild;
	p->lchild=p->rchild;
	p->rchild=temp;
}
void Tree::eraseTree(Node *p)
{
	eraseTree(p->lchild);
	eraseTree(p->rchild);
	delete p;
	cout<<p->data<<" deleted!";
}
int main() {

	Tree t;
	t.createTree();
	t.preorderTraversal();
	t.inorderiter();
	t.postorderTraversal();
	return 0;
}
