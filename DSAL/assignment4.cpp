//============================================================================
// Name        : assignment4.cpp
// Author      : Sharvi Endait
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define max 200 //will indicate the size of the hash table

class HashEntry{
	
private:
	string key;
	string value;
	
public:
	HashEntry()
	{
		key="";
		value="";
	}
	HashEntry(string n,string t)
	{
		key=n;
		value=t;
	}
	friend class TelephoneDict;
};
class TelephoneDict
{
private:
	HashEntry h[max];
	
public:
	int hashfunction(string n)
	{
//		int i=int(n[0])-97;
//		return i;
		int result;
		int sum=0;
		for(int i=0;i<int(n[0]);i++)
		{
			result=((int(n[i])-97)*(i+1));
			sum=sum+result;
		}
		return sum%10;
	}
	
	void insert(string n,string t);
};
void TelephoneDict::insert(string n,string t)
{
	int index=hashfunction(n);
	//without replacement insertion in a hashtable
	if(h[index]=="")
	{
		h[index].key=n;
		h[index].value=t;
	}
	else
	{
		while(index!=h[max])
		{   
			int x=index+1;
			if(h[x]=="")
			{
				h[x].key==n;
				h[x].value==t;
				break;
			}
			else
			{
				x++;
				if(x==h[max])
				{
					x==0;
					
				}
			}
		}
	}
	
	
	
}
int main()
{
	return 0;
}






