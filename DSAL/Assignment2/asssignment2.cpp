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
   Node *deleteword(Node *p,string word);
   Node *inorder_succ(Node *p);
   void updatemeaning(string w);
   void updateword(string w);
};
void BST::search(string w)
{
  Node *p=root;
  int count=0;
  if(p==nullptr)
      return ;
  while(p!=nullptr)
  {
      if(p->word==w)
      {
         cout<<"Word found! the meaning of the entered word is : "<<p->meaning<<endl;
          count++;
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
          cout<<"Word is already present in the dictionary !!";
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
Node* BST::deleteword(Node *t,string w)
{
  //Node *t=root;
  Node *p;
  Node *r;
  if(root==nullptr)
  {
      cout<<"No node to delete!"<<endl;
      return nullptr;
  }
  if(w < t->word)
  {
    t->lchild=deleteword(t->lchild,w);
  }
  else if(w> t->word)
  {
      t->rchild=deleteword(t->rchild,w);
  }
  else// the word is found
  {
      if(t->lchild==nullptr && t->rchild==nullptr)
      {   
          cout<<t->word<<" is deleted!"<<endl;
          delete t;
          t=nullptr;
          return nullptr;
      }
      else if(t->lchild && t->rchild)
      {
          Node *copynode=inorder_succ(t);
          copynode->word=t->word;
          copynode->meaning=t->meaning;
          t=deleteword(t,copynode->word);
      }
      else 
      {
        //   Node *child=(t->lchild)?(t->lchild):(t->rchild);
        //   Node *current=t;
        //   t=child;
        //   cout<<w<<" is deleted!"<<endl;
        //   delete current;  
        if(t->lchild==nullptr)
        {
          Node *temp=t->rchild;
          delete t;
          return temp;
        }
        else
        {
            Node *temp=t->lchild;
            delete t;
            return temp;
        }
        cout<<t->word<<" is deleted!"<<endl;
      }
  }
  return t;
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
void BST::updatemeaning(string w)
{
    Node *p=root;
    string updatemeaning;
    while(p!=nullptr)
    {
        if(p->word==w)
        {
            cout<<"Enter the meaning of the word you want to update to: "<<endl;
            cin>>updatemeaning;
            p->meaning=updatemeaning;
            cout<<"Word meaning updated in the dictionary!!"<<endl;
            display(getRoot());
            break;
        }
        else if(p->word <w)
        {
            p=p->rchild;
        }
        else
        {
            p=p->lchild;
        }
    }
}
void BST::updateword(string w)
{
	string newword;
	string newmeaning;
	/*
	 * 1.search the keyword
	 * 2.Delete the keyword
	 * 3.accept the new word
	 * 4.insert the new keyword
	 */
	deleteword(getRoot(),w);
	cout<<"Enter the new word to be inserted :";
	cin>>newword;
	cout<<"Enter the new meaning to be inserted :";
    cin>>newmeaning;
	insert(newword,newmeaning);
	display(getRoot());
	cout<<"New word added !"<<endl;

}
int main()
{   
   string word;
   string word2;
   string word3;
   string word4;
   string meaning;
   BST dictionary;
   int ch;
   do{
   cout<<"******** MENU **********"<<endl;
   cout<<"1. Create dictionary "<<endl;
   cout<<"2. Display the dictionary in ascending order"<<endl;
   cout<<"3. Display the dictionary in descending order "<<endl;
   cout<<"4. Search a meaning in the dictionary "<<endl;
   cout<<"5. Delete a word in the dictionary"<<endl;
   cout<<"6. Update a word in the dictionary"<<endl;
   cout<<"7. Update a word in the dictionary"<<endl;
   cout<<"8. Exit "<<endl;
   cout<<"Enter your choice:";
   cin>>ch;
   switch (ch)
   {
      case 1:
      cout<<"*******DICTIONARY*****"<<endl;
      dictionary.create();
      break;

      case 2:
      cout<<"Displaying the dictionary in ascending order :"<<endl;
      dictionary.display(dictionary.getRoot());
      break;

      case 3:
      cout<<"Displaying the dictionary in descending order :"<<endl;
      dictionary.reversedDisplay(dictionary.getRoot());
      break;

      case 4:
      cout<<"Enter the word whose meaning you want to find in the dictionary :"<<endl;
      cin>>word;
      dictionary.search(word);
      break;

      case 5:
      cout<<"Enter the word that is to be deleted from the dicionary : "<<endl;
      cin>>word2;
      dictionary.deleteword(dictionary.getRoot(), word2);
      break;

      case 6:
      cout<<"Enter the word whose meaning is to be updated :"<<endl;
      cin>>word3;
      dictionary.updatemeaning(word3);
      break;

      case 7:
      cout<<"Enter the word to be updated :"<<endl;
      cin>>word4;
      dictionary.updateword(word4);
      break;
      
      case 8:
      cout<<"Exiting..."<<endl;
      break;
   }
   }
   while(ch!=8);
  return 0;
}