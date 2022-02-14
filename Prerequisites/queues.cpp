//implementing queues
//FIFO or LILO
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
    friend class Queue;
};
class Queue
{
    private:
    Node *front;//for deletion
    Node *rear;//for insertion

    public:
    Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    void display();
};
Queue::Queue()
{
    front=nullptr;
    rear=nullptr;
}
void Queue::enqueue(int x)
{
  Node *t=new Node(x);
  if (t==nullptr)
  {
      cout<<"Queue overflow"<<endl;
  }
  else
  {
      //t->data=x;
      t->next=nullptr;
      if(front==nullptr)
      {
          front=t;
          rear=t;
      }
      else
      {
          rear->next=t;
          rear=t;
      }
  }
}
int Queue::dequeue()
{
    int x=-1;
    Node *p;
    if(!isEmpty())
    {
        p=front;
        x=p->data;
        front=front->next;
        delete p;
        return x;
    }
    return -1;
}
bool Queue::isEmpty()
{
    if(front==nullptr)
      return true;
    else
      return false;  
}
void Queue::display()
{
    Node *p=front;
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
  Queue q;
  int n;
  cout<<"Enter the number of elements:"<<endl;
  cin>>n;
  int element[n];
  for(int i=0;i<n;i++)
  {
      cout<<"Enter element "<<i<<":";
      cin>>element[i];
      q.enqueue(element[i]);
  }
  q.display();
  return 0;
}