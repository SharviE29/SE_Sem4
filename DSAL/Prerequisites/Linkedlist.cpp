//SLL

#include<iostream>
using namespace std;
class Node
{
  private:
  int data;
  Node *next;

  public:
  Node()
  {
    data=0;
    next=nullptr;
  }
  Node(int x)
  {
    data=x;
    next=nullptr;
  }
  friend class SLL; 
};
class SLL
{
  private:
  Node *head;
  Node *tail;

  public:
  SLL()
  {
    head=nullptr;
    tail=nullptr;
  }
  void display();
  void insertNodeatEnd(int x);
  void insertNodeatStart(int x);
  void insertNodeinBetween(int x,int pos);
  int deleteNode(int pos);
  void reverse();
  void reverse2(Node *,Node *);
  void concatenate(Node *,Node *);
  Node *merging(Node *,Node *);
  void sort();
};
void SLL::display()
{ 
  Node *p;
  if(p)
  {
    cout<<p->data<<" ";
    p=p->next;
  }
  cout<<endl;
}
void SLL::insertNodeatEnd(int x)
{
  Node *p=new Node(x);
  p->next=nullptr;
  if (head==nullptr)
  {
    head=p;
    tail=p;
  }
  else
  {
    tail->next=p;
    p=tail;
  }
}
void SLL::insertNodeatStart(int x)
{
  Node *p=new Node(x);
  p->next=nullptr;
  if(head==nullptr)
  {
    head=p;
    tail=nullptr;
  }
  else
  {
    p->next=head;
    p=head;
  }
}
void SLL::insertNodeinBetween(int x,int pos)
{
  Node *p=new Node(x);
  Node *t=head;
  p->next=nullptr;
  if(head==nullptr)
  {
    head=p;
    tail=nullptr;
  }
  else
  {
    for(int i=0;i<pos-1;i++)
    {
      t=t->next;
    }
    p->next=t->next;
    t->next=p;
  }
}
int SLL::deleteNode(int pos)
{
  Node *t=head;
  Node *p=head->next;
  int x=-1;
  if(pos==1)
  {
    t=head;
    x=head->data;
    head=head->next;
    delete t;
    return x;
  }
  else
  {
    for(int i=0;i<pos-1;i++)
    {
      p->next;
      t=t->next;
    }
    t->next=p->next;
    x=t->data;
    delete t;
    return x; 
  }
}
void SLL::reverse()
{
  Node *p=head,*q=nullptr,*r=nullptr;
  while(p!=nullptr)
  {
    r=q;
    q=p;
    p=p->next;
    q->next=r;
  }
  head=q;
}
void SLL::reverse2(Node *q,Node *p)
{
  Node *p=head;
  Node *q=nullptr;
  if(p)
  {
    reverse2(p,p->next);
    p->next=q;
  }
}
void SLL::concatenate(Node *p,Node *q)
{
   //Node *p=tail;
    if(p->next==nullptr)
      p->next=q;
    else
       concatenate(p->next,q);   
}
void SLL::sort()
{
  Node *p=head;
  Node *index=nullptr;
  int temp;
  if(head==nullptr)
     return ;
  else
  {
    while(p!=nullptr)
    {
        index=p->next;
        while(index!=nullptr)
        {
          if(p->data>index->data)
          {
            temp=p->data;
            p->data=index->data;
            index->data=temp;
          }
          index=index->next;
        }
      p=p->next;
    }
  }
}
Node* SLL::merging(Node *p,Node *q)
{
  Node *last;
  Node *third=nullptr;
  if(p->data<=q->data)
  {
     third=p;
     p=p->next;
  }
  else
  {
    third=q;
    q=q->next;
  }

  Node *tail3=third;
  while(p!=nullptr and q!=nullptr)
  {
    Node *temp=nullptr;
    if(p->data <=q->data)
    {
      temp=p;
      p=p->next;
    }
    else
    {
      temp=q;
      q=q->next;
    }

    tail3->next=temp;
    tail3=temp;
  }
  if (p!=nullptr)
  {
    tail3->next=p;
  }
  else if(q!=nullptr)
  {
    tail3->next=q;
  }
  return third;
}
int main()
{
  return 0;
}

