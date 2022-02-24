/*
 * Assignment 3
 * Threaded binary tree
 */
#include<iostream>
using namespace std;
class Node
{
private:
	int data;
	Node *lchild;
	Node *rchild;
	bool lflag;
	bool rflag;

public:
	Node()
	{
		data=0;
		lchild=rchild=nullptr;
		lflag=rflag=false;
	}
	Node(int x)
	{
		data=x;
		lchild=rchild=nullptr;
	    lflag=rflag=false;

	}
	friend class TBT;
};
class TBT
{
private:
	Node *root;
	Node *header;
public:
	TBT()
	{
		root=nullptr;
		header=nullptr;
	}
	void insert(int key);
	void display();
	Node *inorderSucc(Node *p);
};
void TBT::insert(int key)
{
	Node *p=root;
		if(root==nullptr)
		{
			root=new Node(key);
			header=new Node(-1);
			root->lchild=root->rchild=header;
			header->rchild=header;
			header->lchild=root;
		}
		else
		{
			while(true)
			{
					if(p->data >key)
					{
						if(p->lflag==1)
						{
							p=p->lchild;
						}
						else
						{
							Node *temp=new Node(key);
							temp->lchild=p->lchild;
							temp->rchild=p;
							p->lchild=temp;
							p->lflag=1;
						}
					}
					else
					{
						if(p->lflag==1)
						{
								p=p->rchild;
						}
						else
						{
							Node *temp=new Node(key);
							temp->rchild=p->rchild;
							temp->lchild=p;
							p->rchild=temp;
							p->rflag=1;
						}
					}
			}
	}
}

void TBT::display()//inorder display
{
  Node *p=root;
  while(p->rchild!=header)
  {
	  while(p->lflag==1)
	  {
		  p=p->lchild;
	  }
	  cout<<p->data<<endl;
	  if(p->rflag==1)
	  {
		  p=p->rchild;
	  }
	  else
	  {
		  p=p->rchild;
		  cout<<p->data<<endl;
		  p=p->rchild;
	  }
  }
//  while(p)
//  {
//
//  }
}
int main()
{
 TBT first;
 first.insert(30);
 first.insert(20);
 first.insert(31);
 first.insert(40);
 first.insert(50);
 first.insert(6);
 first.display();
 return 0;
}