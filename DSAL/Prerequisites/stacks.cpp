
//implementing stacks 
//LIFO or FILO

#include<iostream>
using namespace std;
class Node
{

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
  friend class Stack;
};
class Stack
{
   private:
   Node *top;
   public:
   Stack()
   {
       top=nullptr;
   }
   void push(int x);
   int pop();
   void display();
   int stackTop();
   bool isEmpty();
//    bool isFull();
};
void Stack::push(int x)
{
    Node *t=new Node(x);
    if (t==nullptr)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {  
       if(top==nullptr)
       {
           top=t;
           return ;
       }
       //t->data=x;
       t->next=top;
       top=t;
    }
}
int Stack::pop()
{
    int x=-1;
    Node *t;
    if (isEmpty())
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        t=top;
        x=t->data;
        top=top->next;
        delete t;
    }
    return x;
}
int Stack::stackTop()
{
    // Node *t=top;
    // t=top;
    if(top!=nullptr)
      return top->data;
    return -1;  
}
bool Stack::isEmpty()
{
    // Node *t;
    if (top==nullptr)
       return true;
    return false;   
}
// bool Stack::isFull()
// {
//     Node *t=new Node();
//     if (t==nullptr)
//        return true;
//     return false;   
// }
void Stack::display()
{
    Node *p=top;
    // p=top;
    while (p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{  
   Stack s;
   int n;
   cout<<"Enter the number of elements you wish to add in the stack: !"<<endl;
   cin>>n;
   int elements[n];
   for(int i=0;i<n;i++)
   {   
       cout<<"Enter the element "<<i<<":";
       cin>>elements[i];
       s.push(elements[i]);
   }
   s.display();
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   s.display();
   return 0;
}