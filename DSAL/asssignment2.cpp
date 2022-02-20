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
   void deleteword(Node *p,string word);
   Node *inorder_succ(Node *p);
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
 cout<<"The number of comparisons taken to the find the entered word were: "<<count<<endl;
}
void BST::insert(string w,string m)
{
  Node *t=root;
  Node *p;
  Node *r;
  if(root==nullptr)
  {
      root=new Node(w,m);
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
        cout<<p->word<<":"<<p->meaning;
        display(p->rchild);
    }
    cout<<endl;
}
void BST::reversedDisplay(Node *p)
{
    if(p)
    {
        display(p->rchild);
        cout<<p->word<<":"<<p->meaning;
        display(p->lchild);
    }
    cout<<endl;
}
Node *BST::inorder_succ(Node *p)//here p is the node that is to be deleted
{
    Node *child=p->rchild;
    while(child)
    {
        child->lchild;
    }
    return child;
    //child will be pointing at the inorder succesor now
}
void BST::deleteword(Node *t,string w)
{
  //Node *t=root;
  Node *p;
  Node *r;
  if(root==nullptr)
  {
      cout<<"No node to delete!"<<endl;
      return ;
  }
  if(w < t->word)
  {
    deleteword(t->lchild,w);
  }
  else if(w> t->word)
  {
      deleteword(t->rchild,w);
  }
  else// the word is found
  {
      if(t->lchild==nullptr && t->rchild==nullptr)
      {   
          cout<<t->word<<" is deleted!"<<endl;
          delete t;
          t=nullptr;
      }
      else if(t->lchild && t->rchild)
      {
          Node *copynode=inorder_succ(t);
          copynode->word=t->word;
          copynode->meaning=t->meaning;
          deleteword(t->lchild,copynode->word);
      }
      else 
      {
          Node *child=(t->lchild)?(t->lchild):(t->rchild);
          Node *current=t;
          t=child;
          cout<<w<<" is deleted!"<<endl;
          delete current;  
      }
  }
  }
void BST::create()
{
  int n;
  string word;
  string meaning;
  cout<<"Enter the number of words to be inserted: "<<endl;
  cin>>n;
  for (int i=0;i<n;i++)
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
   string word2;
   string meaning;
   BST dictionary;
   
   dictionary.create();
   cout<<"************************"<<endl;
   cout<<"Created dictionary is: "<<endl;
   cout<<"Ascending order: "<<endl;
   dictionary.display(dictionary.getRoot());
   cout<<"Descending order :"<<endl;
   dictionary.reversedDisplay(dictionary.getRoot());
   cout<<"************************"<<endl;
   cout<<"Enter the word to be searched :"<<endl;
   cin>>word;
   dictionary.search(word);
   cout<<"Enter the word to be deleted: "<<endl;
   cin>>word2;
   dictionary.deleteword(dictionary.getRoot(),word2);
   cout<<"Dictionary: "<<endl;
   dictionary.display(dictionary.getRoot());
  return 0;

}