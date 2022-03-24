//============================================================================
// Name        : Assignment4.cpp
// Author      : Sharvi Endait
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
Consider telephone book database of N clients. Make use of a hash table
implementation to quickly look up client‘s telephone number. Make use of two
collision handling techniques and compare them using number of comparisons
required to find a set of telephone numbers (use linear probing with replacement and
without replacement)
*/

#include<iostream>
using namespace std;
class HashEntry
{
    private:
    int key;
    long int teleno;

    public:
    HashEntry()
    {
        key=0;
        teleno=0;
    }
    HashEntry(int a, long int t)
    {
        key=a;
        teleno=t;
    }

    friend class TelephoneDict;
};
class TelephoneDict
{
    HashEntry h[10];
    //int n;
    int id;
    int index;
    long int telephoneno;
    public:
    int hashfunction(int n)
    {

        index=n%10;
        return index;
    }
    void createRecord(int id,long int teleno);
    void createRecordWithReplace(int id,long int teleno);
    void searchRecord(int id,long int teleno);
    void searchRecordWithReplace(int id,long int teleno);
    void deleteRecord();
    void updateRecord();
    void display();
};
void TelephoneDict::createRecord(int id,long int telephoneno)
{
        int value=hashfunction(id);
        while(true)
        {
			if(h[value].key==0)
						{
						h[value].key=id;
						h[value].teleno=telephoneno;
						break;
						}
			else{
				for(int i=1;i<10;i++)
				{
				   value=(value+i)%10;
				   break;
				}
			}
        }
}
void TelephoneDict::createRecordWithReplace(int id,long int teleno)
{
	int value=hashfunction(id);
	int tempkey;
	long int tempphno;
	if(h[value].key==0)
	{
		h[value].key=id;
		h[value].teleno=teleno;
		bool flag=1;
	}
	else
	{
		if(h[value]%10==value)//the already existing key is present at the right slot
		{
			//linear probing
			value=(value+1)%10;
			if(h[value].key==0)
				{
					h[value].key=id;
					h[value].teleno=teleno;
					bool flag=1;
					break;
				}
			else
			{
				value=(value+1)%10;
			}
		}
		else//wrong key is present in the slot
		{
			tempkey=h[value].key;
			tempphno=h[value].teleno;
			h[value].key=id;
			h[value].teleno=teleno;
			for(int i=1;i<10;i++)
			{
				value=(value+i)%10;
				if(h[value].key==0)
				{
					h[value].key=tempkey;
					h[value].teleno=tempphno;
					break;
				}
			}
		}

	}
}
void TelephoneDict::searchRecordWithReplace(int id, long int teleno)
{
	int value=hashfunction(id);
		int tempkey;
		long int tempphno;
		if(h[value].key==id)
		{
			cout<<"Record found!"<<endl;
		}
		else
		{
			for(int i=1;i<10;i++)
			{
				value=(value+i)%10;
			    break;
			}


		}
}
void TelephoneDict::searchRecord(int id,long int telephoneno)
{
        int newindex=hashfunction(id);
        while(true)
        {
            if(h[newindex].key==id)
            {
            cout<<"Record found!"<<endl;
            cout<<"Following is the result:"<<endl;
            cout<<h[newindex].key<<":"<<h[newindex].teleno<<endl;
            break;
            }
            else{
            	for(int i=1;i<10;i++)
            	{
            		newindex=(newindex+i)%10;
            		break;
            	}
            }
        }
}
void TelephoneDict::deleteRecord()
{
     int id1,telephoneno1;
        int newindex;
        int i=1;
        cout<<"Enter the id: "<<endl;
        cin>>id1;
        cout<<"Enter the corresponding telephone number: "<<endl;
        cin>>telephoneno1;
        int newindex=hashfunction(id1);
        //int value=id%10;
        for (int j=0;j<10;j++)
        {
            if(h[newindex].teleno==telephoneno1)
            {
            h[newindex].key=0;
            h[newindex].teleno=0;
            cout<<"Record deleted!"<<endl;
            cout<<"Following is the result:"<<endl;
            cout<<h[newindex].key<<":"<<h[newindex].teleno<<endl;
            break;
            }
            else
            {
                newindex=(newindex+i)%10;
                i++;
                if(i==11)
                   cout<<"Number not found"<<endl;
                   break;
            }
        }
}
void TelephoneDict::updateRecord()
{
        int id1,telephoneno1;
        int newindex;
        long int newnumber;
        int i=1;
        cout<<"Enter the id: "<<endl;
        cin>>id1;
        cout<<"Enter the corresponding telephone number to be updated: "<<endl;
        cin>>telephoneno1;
        int newindex=hashfunction(id1);
        //int value=id%10;
        for (int j=0;j<10;j++)
        {
            if(h[newindex].teleno==telephoneno1)
            {
            // h[newindex].key=0;
            // h[newindex].teleno=0;
            // cout<<"Record deleted!"<<endl;
            // cout<<"Following is the result:"<<endl;
            // cout<<h[newindex].key<<":"<<h[newindex].teleno<<endl
            cout<<"Enter the updated telephone number: "<<endl;
            cin>>newnumber;
            h[newindex].key=id;
            h[newindex].teleno=newnumber;
            cout<<"Following data has been updated!"<<endl;
            break;
            }
            else{
                 newindex=(newindex+i)%10;
                i++;
                if(i==11)
                   cout<<"Number not found"<<endl;
                   break;
            }
        }
}
void TelephoneDict::display()
{

}
int main()
{

   return 0;
}
