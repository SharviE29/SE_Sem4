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
	    lflag=rflag=false;//node
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
					if(p->data >key)//modify the left child of the tree
					{
						if(p->lflag==false)// the left child of the tree is a node 
						{
							p=p->lchild;
						}
						else //is a thread
						{
							Node *temp=new Node(key);
							temp->lchild=p->lchild;
							temp->rchild=p;
							p->lchild=temp;
							p->lflag=false;//make it a node
							break;
						}
					}
					else //modify the right child of the tree
					{
						if(p->rflag==false)
						{
								p=p->rchild;
						}
						else
						{
							Node *temp=new Node(key);
							temp->rchild=p->rchild;
							temp->lchild=p;
							p->rchild=temp;
							p->rflag=false;
							break;
						}
					}
			}
	}
}

void TBT::display()//inorder display
{
  Node *p=root;
  if(root==nullptr)
  {
	  cout<<"Tree is empty";
	  return ;
  }
  while(p!=header)
  {
	  while(p->lflag==false)//node
	  {
		  p=p->lchild;
	  }
	  cout<<p->data<<" ";
	  while(p->rflag==true && p->rchild!=header)
	  {
		  p=p->rchild;
		  cout<<p->data<<" ";
	  }
	  p=p->rchild;
  }

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
