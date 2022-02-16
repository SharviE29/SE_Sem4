#include<iostream>
using namespace std;

class Node{
    private:
    string word;
    string meaning;
    Node *lchild;
    Node *rchild;

    public:
    Node()
    {
        word="";
        meaning="";
        lchild=nullptr;
        rchild=nullptr;
    }
    Node(string w,string m)
    {
        word=w;
        meaning=m;
        lchild=rchild=nullptr;
    }
    friend class BST;
};
class BST
{
   private:
   Node *root;

   public:
   BST()
   {
       root=nullptr;
   }
   Node *getRoot()
   {
       return root;
   }
   void insert(string w,string m);
   Node* search(string w);
   void display(Node *p);//inorder display for ascending order display
};
Node *BST::search(string w)
{
  Node *p=root;
  while(p!=nullptr)
  {
      if(p->word==w)
      {
          return p;
      }
      else if(p->word < w)
      {
          p=p->rchild;
      }
      else if(p->word > w)
      {
          p=p->lchild;
      }
  }
  return nullptr;
}
void BST::insert(string w,string m)
{
  Node *t=root;
  Node *p;
  Node *r;
  if(root==nullptr)
  {
      p=new Node(w,m);
      p->lchild=p->rchild=nullptr;
      root=p;
      return ;
  }
  while(t!=nullptr)
  {
      r=t;
      if(p->word==w)
      {
          return ;
      }
      else if(p->word >w)
      {
          p=p->lchild;
      }
      else if(p->word < w)
      {
          p=p->rchild;
      }
  }
 p=new Node(w,m);
 //p->word=w;
 p->lchild=p->rchild=nullptr;
    if(w > r->word)
    {
        r->rchild=p;
    }
    else
    {
        r->lchild=p;
    }
}
void BST::display(Node *p)
{
    if(p)
    {
        display(p->lchild);
        cout<<p->word<<" ";
        display(p->rchild);
    }
}
int main()
{   
    BST obj;
    obj.insert("a","abcd");
    obj.insert("b","bcdde");
    obj.display(obj.getRoot());
    return 0;

}