/*
1. -Inorder , preorder, postorder traversals both recursive and non recursive
2. -Change the tree such that the left and the right pointers are swapped
3. -Find the height of the tree
4. -Copy the tree
5. -Count the number of leaves , internal nodes
6. -Erase all the nodes in a binary tree
*/

#include<iostream>
#include "queues.h"
using namespace std;
class BinaryTree
{
private:
   Node *root;

public:
BinaryTree()
{
    root=nullptr;
}
    void createTree();
    Node* create_rec();
    
    //iterative traversals
    void preOrder(Node *p);
    void inOrder(Node *p);
    void postOrder(Node *p);
    void levelOrder(Node *p);

    //recursive traversals
    void preorder_iter(Node *p);
    void inorder_iter(Node *p);
    void postOrder_iter(Node *p);

    //recursive operations
    int height(Node *p);
    int count(Node *p);
    void mirror(Node *p);
    void eraseTree(Node *p);
    Node *copy(Node *&,Node *&);

    //iterative operations
    int height_iter(Node *p);
    void mirror_iter(Node *p);
    void copy_iter(Node *p);


    void preOrder()
    {
        preOrder(root);
    }
    void postOrder()
    {
        postOrder(root);
    }
    void inOrder()
    {
        inOrder(root);
    }
};
void BinaryTree::createTree()
{
    Node *p,*temp;
    int x;
    Queue q(150); 
    cout<<"Enter the value of the root node: ";
    cin>>x;
    root=new Node(x);
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p=q.dequeue();
        cout<<"Enter the left child of "<<p->data<<":";
        cin>>x;
        if(x!=-1)
        {
            temp=new Node(x);
            p->lchild=temp;
            q.enqueue(temp);
        }
        cout<<"Enter the right child of "<<p->data<<":";
        cin>>x;
        if(x!=-1)
        {
            temp=new Node(x);
            p->rchild=temp;
            q.enqueue(temp);
        }
    }
}
//recursive traversals

void BinaryTree::inOrder(Node *p)
{
    if(p!=nullptr)
    {
        inOrder(p->lchild);
        cout<<p->data<<" ";
        inOrder(p->rchild);
    }
}
void BinaryTree::preOrder(Node *p)
{
    if(p!=nullptr)
    {
        cout<<p->data<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
void BinaryTree::postOrder(Node *p)
{
    if(p!=nullptr)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout<<p->data<<" ";
    }
}
//recursive creation
Node *BinaryTree::create_rec()
{   
    int x;
    cout<<"Enter data:";
    cin>>x;
    if(x==-1){
        return nullptr;
    }
    else {
        Node *p=new Node(x);
        cout<<"Enter the left child of "<<x<<":"<<endl;  
        p->lchild=create_rec();
        cout<<"Enter the right child of "<<x<<":"<<endl;
        p->rchild=create_rec();
        return p;
    }
}
//iterative traversals
void BinaryTree::preorder_iter(Node *p)
{
    Stack s(100);
    s.push(p);
    while(p!=nullptr || !s.isEmpty())
    {
        if(p!=nullptr)
        {
            cout<<p->data<<" ";
            s.push(p);
            p=p->lchild;
        }
        else
        {
            p=s.stackTop();
            s.pop();
            p=p->rchild;
        }
    }
}
void BinaryTree::inorder_iter(Node *p)
{
    Stack s(100);
    while(p!=nullptr || !s.isEmpty())
    {
        if(p!=nullptr)
        {
            s.push(p);
            p=p->lchild;
        }
        else
        {
            p=s.pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}
//using 2 stacks
void BinaryTree::postOrder_iter(Node *p)
{
  Stack s1(100);
  Stack s2(100);
  Node *temp;
  Node *temp1;
  if(p!=nullptr)
  {
      s1.push(p);
      while(!s1.isEmpty())
      {
          temp=s1.stackTop();
          s1.pop();
          s2.push(temp);
          if(temp->lchild)
          {
              s1.push(temp->lchild);
          }
          if(temp->rchild)
          {
              s1.push(temp->rchild);
          }
      }
      while(!s2.isEmpty())
      {
          temp1=s2.stackTop();
          s2.pop();
          cout<<temp1->data<<" ";
      }
  }
}
void BinaryTree::levelOrder(Node *p)
{
    Queue q(1000);
    cout<<p->data<<" ";
    q.enqueue(p);
    while(!q.isEmpty())
    {   
        p=q.dequeue();
        if(p->lchild)
        {
          cout<<p->lchild->data<<" ";
          q.enqueue(p->lchild);  
        }
        if(p->rchild)
        {
          cout<<p->rchild->data<<" ";
          q.enqueue(p->rchild);  
        }
    }
}
int BinaryTree::height(Node *p)
{
//    int x=0,y=0;
//    if(p==0)
//      return 0;
//     x=height(root->lchild);
//     y=height(root->rchild);
//     if(x>y)
//       return x+1;
//     else 
//       return y+1; 
    if(p==nullptr)
        return 0;
    return 1 + max(height(p->lchild),height(p->rchild));          
}
int BinaryTree::count(Node *p)
{
    int x,y;
    if(p!=nullptr)
          x=count(p->lchild);
          y=count(p->rchild);
       return x+y+1;
    return 0;
}
void BinaryTree::mirror(Node *p)
{
    if(p==nullptr)
       return ;
    else
    {
        Node *temp;
        mirror(p->lchild);
        mirror(p->rchild);
        temp=p->lchild;
        p->lchild=p->rchild;
        p->rchild=temp;
    }   
}
void BinaryTree::eraseTree(Node *p)
{
    if(p==nullptr)
      return ;
    else
    {
        eraseTree(p->lchild);
        eraseTree(p->rchild);
        cout<<p->data<<" deleted"<<endl;
        delete p;
    }  
}
Node *BinaryTree::copy(Node *&p1,Node *&p2)
{
    if(p2==nullptr)
       return nullptr;
    Node *temp=new Node(p2->data);
    if(p1==nullptr)
       return nullptr;
    temp->lchild=copy(p1, p2->lchild);
    temp->rchild=copy(p1, p2->rchild);
    return temp;
}
int BinaryTree::height_iter(Node *p)
{  
    Queue q(100);
    int height=0;
    int nc=0;
    while(!q.isEmpty())
    {
        nc=q.sizeofqueue();
        height++;
        while(nc>0)
        {
            p=q.dequeue();
            if(p->lchild)
            {
                q.enqueue(p->lchild);
            }
            if(p->rchild)
            {
                q.enqueue(p->rchild);
            }
            nc--;
        }
    }   
}
void BinaryTree::mirror_iter(Node *p)
{
   Stack s(1000);
   s.push(p);
   while(!s.isEmpty())
   {
       Node *temp=s.stackTop();
       s.pop();
       Node *tem=temp->lchild;
       temp->lchild=temp->rchild;
       temp->rchild=tem;
       if(temp->lchild)
       {
           s.push(temp->lchild);
       }
       if(temp->rchild)
       {
           s.push(temp->rchild);
       }
   }
}
int main()
{
    BinaryTree t;
    Node *s=t.create_rec();
    int choice;
    do
    {
      cout<<"**********************\n";
      //cout<<"1.Create tree\n";
      cout<<"2.Preorder traversal\n";
      cout<<"3.Postorder traversal\n";
      cout<<"4.Inorder traversal\n";
      cout<<"5.Preorder iterative\n";
      cout<<"6.Inorder iterative\n";
      cout<<"7.Postorder iterative\n";
      cout<<"8.Height of tree\n";
      cout<<"9.Number of nodes\n";
      cout<<"10.Mirror tree\n";
      cout<<"11.Copy of a tree\n";
      cout<<"12.Erase tree\n";
      cout<<"13.Exit\n";
      cout<<"Enter your choice:";
      cin>>choice;
      switch (choice)
      {
        // case 1:
        //     t.create_rec();
        //     break;

        case 2:
            t.preOrder(s);
            break;

        case 3:
            t.postOrder(s);
            break;

        case 4:
            t.inOrder(s);
            break;

        case 5:
            t.preorder_iter(s);
            break;             
        
        case 6:
            t.inorder_iter(s);
            break;    

        case 7:
            t.postOrder_iter(s);
            break;

        case 8:
            cout<< "Height of the tree is : "<<t.height(s)<<endl;
            break;  

        case 9:
            cout<<"Number of nodes in the following tree : "<<t.count(s)<<endl;
            break;

        case 10:
        {
            t.mirror(s);
            cout<<"Mirror preorder traversal: ";
            t.preOrder(s);       
            break;   
        }         
        
        case 11:
        {
            BinaryTree newtree=t;
            newtree.preOrder();
            break;
        }

        case 12:
        {
            t.eraseTree(s);  
            break;
        }

        case 13:
            cout<<"Exiting....";
            break;      

        // default:
        //     break;
      } 
    } while (choice!=13);    
    return 0;
}