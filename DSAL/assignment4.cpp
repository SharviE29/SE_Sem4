

// #include <iostream>
// using namespace std;
// #define max 200 //will indicate the size of the hash table

// class HashEntry{
	
// private:
//     int key;
// 	long int teleno;
	
// public:
// 	HashEntry()
// 	{
// 		key=0;
// 		teleno=0;
// 	}
// 	HashEntry(int n,long int t)
// 	{
// 		key=n;
// 		teleno=t;
// 	}
// 	friend class TelephoneDict;
// };
// class TelephoneDict
// {
// private:
//     int index;
// 	HashEntry h[max];
	
// public:
// 	int hashfunction(int n)
// 	{
// 		index=n%10;
// 	}
	
// 	void insert(int n,long int t);
// };
// void TelephoneDict::insert(int n,long int t)
// {
// 	int index=hashfunction(n);
// 	//without replacement insertion in a hashtable
// 	// if(h[index].key== 0)//field is empty
// 	// {
// 	// 	h[index].key=n;
// 	// 	h[index].teleno=t;
// 	// }
// 	//else
// 	//not empty
	
// 		//while(index!=h[max].key)
// 		while(true)
// 		{   
// 			//int x=index+1;
// 			if(h[index].key==0)
// 			{
// 				h[index].key==n;
// 				h[index].teleno==t;
// 				break;
// 			}
// 			else
// 			{
				
// 				if(x==h[max])
// 				{
// 					x==0;
					
// 				}
// 			}
// 		}
// 	}
	
	
	

// int main()
// {
// 	return 0;
// }




#include<iostream>
#include<cstring>
#define max 10
using namespace std;

struct client
{
	long int iPhno;
	char name[20];

};//end of structure 	

class hashtable
{
	client ht[max];
	
	public:
		hashtable()	//constructor
		{
			for(int i=0;i<max;i++)
			{
				ht[i].iPhno=0;
				
			}
		}		
		void insert();
		void display();
		int search(int);
		int del(int);
		int hash(long int);
};//end of class

void hashtable::insert()
{
	client c;
	int iPos;
	char cAns;
	do
	{
		cout<<"\n Enter Phone Number:";
		cin>>c.iPhno;
		iPos=hash(c.iPhno);
	
		if(ht[iPos].iPhno==0)
		{
			ht[iPos]=c;
		}
		else
		{
			for(int i=iPos+1;i%max!=iPos;i++)
			{
				ht[i]=c;
				break;
			}
		}
		cout<<"\n Add More:";
		cin>>cAns;
	}while(cAns=='y' || cAns=='Y');	
}//end  of insert

int hashtable::hash(long int key)
{
	return(key%max);
}//end of hash

void hashtable::display()
{
	cout<<"------------------------------------";
	cout<<"\nSrno\tPhone number\n";
	cout<<"------------------------------------\n";
	for(int i=0;i<max;i++)
	{
		cout<<i<<"\t"<<ht[i].iPhno<<endl;
	}
	cout<<"------------------------------------\n";
}//end of display

int hashtable::search(int x)
{
	int iFlag=0; 
	cout<<"Enter Phone number to be searched:";
	cin>>x;
	for(int i=0;i<max;i++)
	{
		if(ht[i].iPhno==x)
		{
			cout<<"\n Phone Number Found at position "<<i;
			iFlag=1;
		}
	}
	if(iFlag==0)
	cout<<"\n Phone Number Not Found";
}//end of search

int hashtable::del(int s)
{
	int iF=0;
	cout<<"\n Enter phone number to be deleted:";
	cin>>s;
	for(int i=0;i<max;i++)
	{
		if(ht[i].iPhno==s)
		{
			
			ht[i].iPhno=0;
			cout<<"\n Phone number found and deleted";
			iF=1;
		}
	}
	if(iF==0)
	cout<<"\n Phone number not found";

}//end of del	

int main()
{
	int y,s,iCh;
	hashtable h;
	do
	{
		cout<<"\n---------------LIST---------------\n";
		cout<<"\n1.INSERT\n2.DISPLAY\n3.SEARCH\n4.DELETE\n5.EXIT\n\n";
		cout<<"Enter your choice:";
		cin>>iCh;
		cout<<"\n";
		
		switch(iCh)
		{
			case 1://insert
				h.insert();
				cout<<"\n";
				break;
				
			case 2://display
				h.display();
				cout<<"\n";
				break;
				
			case 3://search					
				h.search(y);
				cout<<"\n";
				break;
				
			case 4://delete
				h.del(s);
				cout<<"\n";
				break;
				
			case 5://exit
				break;
		}//end of switch
	}while(iCh!=5);//end of do							
return 0;
}					
						


