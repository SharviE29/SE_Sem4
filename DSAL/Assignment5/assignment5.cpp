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
		wordkey=this->wordkey;
		meaning=this->meaning;
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
			ht[i]==nullptr;
		}
	}
	int hashfunction(string word)
	{   
		int sum=0;
		int result;
		for(int i=0;i<word.length();i++)
		{   
			result=(97-int(word[i])*(i+1));
			sum=sum+result;
		}
		return sum;
	}
	void insert(string,string);
    string search(string);
    void deletekey(string);
    void display();
};

void Dictionary::insert(string a, string b)
{
	int index=hashfunction(a);
    HashEntryNode *temp=new HashEntryNode(a,b);
    temp->wordkey=a;
    temp->meaning=b;
    temp->next=nullptr;
    //no nodes in the list
	if(ht[index]==nullptr)
	{
       ht[index]=temp;
	}
    else{
        HashEntryNode *temp1=ht[index];
        while(temp1->next!=nullptr)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}
string Dictionary::search(string a)
{
    int index=hashfunction(a);
    HashEntryNode *temp=ht[index];
    while(temp!=nullptr)
    {
        if(temp->wordkey==a)
        {
            return temp->meaning;
        }
        temp=temp->next;
    }
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
            if(prev==nullptr)
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
}
void Dictionary::display()
{
    for(int i=0;i<size;i++)
    {
        HashEntryNode *temp=ht[i];
        while(temp!=nullptr)
        {
            cout<<temp->wordkey<<" "<<temp->meaning<<endl;
            temp=temp->next;
        }
    }
}
int main() {
	
    Dictionary d;
    d.insert("hello","hi");
	return 0;
}