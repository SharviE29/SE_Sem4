/*
Implement all the functions of a dictionary (ADT) using hashing and handle
collisions using separate chaining using linked list.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
comparable, Keys must be unique. Standard Operations: Insert (key, value),
Find(key), Delete(key)
*/

#include <iostream>
#include<string>
using namespace std;
#define size 20
class HashEntryNode{
private:
	string wordkey;
	string meaning;
    HashEntryNode *next;
public:
	HashEntryNode()
	{
		wordkey="";
		meaning="";
        next=nullptr;
	}
	HashEntryNode(string wordkey,string meaning)
	{
		this->wordkey=wordkey;
		this->meaning=meaning;
        next=nullptr;
	}
	friend class Dictionary;
};
class Dictionary{
private:
	HashEntryNode *ht[size];

public:
	Dictionary()
	{
		for(int i=0;i<size;i++)
		{
			ht[i]=nullptr;
		}
	}
	int hashfunction(string word)
	{
		long long int i=0;
		int sum=0;
		int result;
		while(i<word.length())
		{
			result=labs(97-int(word[i])*(i+1));
			sum=sum+result;
			i++;
		}
		return sum%size;
	}
	void insert(string,string);
    string search(string);
    void deletekey(string);
    void display();
    void modify(string,string);
};

void Dictionary::insert(string a, string b)
{
	int index=hashfunction(a);
    HashEntryNode *temp=new HashEntryNode(a,b);
//    temp->wordkey=a;
//    temp->meaning=b;
//    temp->next=nullptr;
    //no nodes in the list
	if(ht[index]==nullptr)
	{
       ht[index]=temp;
	}
    else{
        HashEntryNode *temp1=ht[index]; //creating a pointer
        while(temp1->next!=nullptr)//appending the linkedlist
        {
        	if(temp1->wordkey==a){
        		cout<<"The word is already present in the dictionary!"<<endl;
                return ;
        	}
            temp1=temp1->next;
        }


        if(temp1->wordkey==a){
        	cout<<"The word is already present in the dictionary!"<<endl;
        	return ;
        }

        temp1->next=temp;
    }
}
string Dictionary::search(string a)
{
    int index=hashfunction(a);
    int count=0;
    HashEntryNode *temp=ht[index];
    while(temp!=nullptr)
    {
        if(temp->wordkey==a)
        {
        	cout<<"Number of comparisons taken: "<<count<<endl;
            return temp->meaning;
        }
        temp=temp->next;
        count++;
    }
    cout<<"The number of comparisons :"<<count<<endl;
    return "Not Found";
}

void Dictionary::deletekey(string a)
{
    int index=hashfunction(a);
    HashEntryNode *temp=ht[index];
    HashEntryNode *prev=nullptr;
    while(temp!=nullptr)
    {
        if(temp->wordkey==a)
        {
            if(prev==nullptr)//delete first node
            {
                ht[index]=temp->next;
            }
            else{
                prev->next=temp->next;
            }
            delete temp;
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    cout<<"Word deleted !"<<endl;
}
void Dictionary::display()
{
    for(int i=0;i<size;i++)
    {
        HashEntryNode *temp=ht[i];
        if(temp!=nullptr)
        {
			while(temp!=nullptr)
			{
				cout<<i<<" "<<temp->wordkey<<" "<<temp->meaning<<endl;
				temp=temp->next;
			}
        }
    }
}
void Dictionary::modify(string newword,string meaningnew)
{
   int index=hashfunction(newword);
   HashEntryNode *temp=ht[index];
      while(temp!=nullptr)
      {
          if(temp->wordkey==newword)
          {
              temp->meaning=meaningnew;
              cout<<"Word meaning updated !"<<endl;
          }
          else
          {
              temp=temp->next;
          }
      }
}
int main() {

    Dictionary d;
    int ch;
    string word1;
    string word2;
    string word3;
    string meaning1;
    string word4;
    string meaning4;
    do
    {
    	cout<<"1.Insert a word in the dictionary"<<endl;
    	cout<<"2.Search for a word in the dictionary"<<endl;
    	cout<<"3.Delete a word in the dictionary"<<endl;
    	cout<<"4.Update a word in the dictionary"<<endl;
    	cout<<"5.Display the dictionary"<<endl;
    	cout<<"6.Exit"<<endl;
    	cout<<"Enter your choice : "<<endl;
    	cin>>ch;
    	switch(ch)
    	{
    	case 1:
			{
				cout<<"Enter the word to be inserted in the hashtable :"<<endl;
				cin>>word1;
				cout<<"Enter the corresponding meaning: "<<endl;
				cin>>meaning1;
				d.insert(word1, meaning1);
				break;
			}
    	case 2:
    	{
    		cout<<"Enter the word to be searched :"<<endl;
    		cin>>word2;
    		cout<<d.search(word2)<<endl;
    		break;
    	}
    	case 3:
    	{
    		cout<<"Enter the word to be deleted :"<<endl;
    		cin>>word3;
    		d.deletekey(word3);
    		break;
    	}
    	case 4:
    	{
    		cout<<"Enter the word whose meaning is to be updated :"<<endl;
    		cin>>word4;
    		cout<<"Enter its updated meaning: "<<endl;
    		cin>>meaning4;
    		d.modify(word4, meaning4);
    		break;
    	}
    	case 5:
    	{
    		cout<<"Your dictionary !"<<endl;
    		d.display();
    		break;
    	}
    	case 6:
    	{
    		cout<<"Exiting !"<<endl;
    		break;
    	}
      }
    }while(ch!=6);
	return 0;
}