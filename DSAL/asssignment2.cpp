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
   void search(string w);
   void display(Node *p);//inorder display for ascending order display
   void create();
   void reversedDisplay(Node *p);
};
void BST::search(string w)
{
  Node *p=root;
  int count=0;
  while(p!=nullptr)
  {
      if(p->word==w)
      {
         cout<<"Word found! the meaning of the entered word is : "<<p->meaning<<endl;
          break; 
      }
      else if(p->word < w)
      {
          p=p->rchild;
          count++;
      }
      else if(p->word > w)
      {
          p=p->lchild;
          count++;
      }
  }
 cout<<"The number of comparisons taken to the find the entered word were: "<<count;
}
void BST::insert(string w,string m)
{
  Node *t=root;
  Node *p;
  Node *r;
  if(root==nullptr)
  {
      p=new Node(w,m);
      return ;
  }
  while(t!=nullptr)
  {
      r=t;
      if(t->word==w)
      {   
          cout<<"Duplicate found!";
          return ;
      }
      else if(t->word >w)
      {
          t=t->lchild;
      }
      else if(t->word < w)
      {
          t=t->rchild;
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
    cout<<endl;
}
void BST::reversedDisplay(Node *p)
{
    if(p)
    {
        display(p->rchild);
        cout<<p->word<<" ";
        display(p->lchild);
    }
    cout<<endl;
}
void BST::create()
{
  int n;
  string word;
  string meaning;
  cout<<"Enter the number of words to be inserted: "<<endl;
  cin>>n;
  for (int i=0;i<=n;i++)
  {
      cout<<"Enter a word: ";
      cin>>word;
      cout<<"Enter its corresponding meaning: ";
      cin>>meaning;
      insert(word,meaning);
  }
}
int main()
{   
   string word;
   string meaning;
   BST dictionary;
   
   dictionary.create();
   //dictionary.display(dictionary.getRoot());
   cout<<"Enter the word to be searched";
   cin>>word;
   dictionary.search(word);


}