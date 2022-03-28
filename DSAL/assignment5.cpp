//============================================================================
// Name        : Assignment5.cpp
// Author      : Sharvi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;
#define size 20
class HashEntryNode{
private:
	string wordkey;
	string meaning;
public:
	HashEntryNode()
	{
		wordkey="";
		meaning="";
	}
	HashEntryNode(string wordkey,string meaning)
	{
		wordkey=this->wordkey;
		meaning=this->meaning;
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
		for(int i=0;i<word.length;i++)
		{   
			result=(97-int(word[i])*(i+1));
			sum=sum+result;
		}
		return sum;
	}
	void insert(string,string);
};

void Dictionary::insert(string a, string b)
{
	int index=hashfunction(a);
	if(ht[index]==nullptr)
	{
       //create a new node and store the address of the the first node of the ll in the hashtable

	}
}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
