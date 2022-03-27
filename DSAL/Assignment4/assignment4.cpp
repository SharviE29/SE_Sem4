/*
Consider telephone book database of N clients. Make use of a hash table 
implementation to quickly look up client‘s telephone number. Make use of two 
collision handling techniques and compare them using number of comparisons 
required to find a set of telephone numbers (use linear probing with replacement and 
without replacement)
*/

#include<iostream>
using namespace std;
#define size 20

class HashTable
{
    long long int teleno;
    int id;

    public:
    HashTable()
    {
        id=0;
        teleno=0;
    }
    HashTable(int a, long long int t)
    {
        id=a;
        teleno=t;
    }
    friend class TelephoneDict;

};

class TelephoneDict
{  
    private:
    HashTable h[size];
   
    public:
    int hashfunction(long long int n)
    {
      return n%size;
    }
    void createRecord(long long int, int);
    void createrecordwithRepl(long long int, int);
    void searchRecord(long long int);
    void deleteRecord(long long int);
    void updateRecord(long long int);
    void display();

};

void TelephoneDict::createRecord(long long int n, int a)
{
    int index=hashfunction(n);
    do
    {
        if(h[index].id==0)
        {
            h[index].id=a;
            h[index].teleno=n;
            break;
        }
        index=(index+1)%size;
    } while (index!=hashfunction(n));    
}

void TelephoneDict::createrecordwithRepl(long long int n,int a)
{
   int index= hashfunction(n);
   do
   {
      if(h[index].id==0)
      {
         h[index].id=a;
         h[index].teleno=n;
         break;
      }
      else{
          int newIndex=hashfunction(h[index].teleno);
          if(index!=newIndex && index!=hashfunction(n))
          {
             long long int tempkey=h[index].teleno;
             int tempvalue=h[index].id;

             h[index].id=a;
             h[index].teleno=n;
             createrecordwithRepl(tempkey,tempvalue);
             break;
          }
          else{
              index=(index+1)%size;
          }
      }
   } while (index!=hashfunction(n));  
}


void TelephoneDict::searchRecord(long long int n)
{   
    int collisionCount=0;
    int index=hashfunction(n);
    do
    {
        if(h[index].teleno==n)
        {
            cout<<"The id : "<<h[index].id<<endl;
              
        }
        index=(index+1)%size;
        collisionCount++;
    } while (index!=hashfunction(n));
    cout<<"The number of collisions that took place were : "<<collisionCount<<endl;
}

void TelephoneDict::updateRecord(long long int n)
{
    int index=hashfunction(n);
    do
    {
        if(h[index].teleno==n)
        {
            cout<<"Enter the new id: "<<endl;
            int newid;
            cin>>newid;
            h[index].id=newid;
            cout<<"Updated!"<<endl;
        }
        index=(index+1)%size;
    } while (index!=hashfunction(n));
}
void TelephoneDict::display()
{
    for(int i=0;i<size;i++)
    {
        if(h[i].id!=0)
        {
            cout<<"The id: "<<h[i].id<<" and the telephone number: "<<h[i].teleno<<endl;
        }
    }
}
void TelephoneDict::deleteRecord(long long int n)
{
   int index=hashfunction(n);
    do
    {
        if(h[index].teleno==n)
        {
            h[index].id=0;
            h[index].teleno=0;
            break;
        }
        index=(index+1)%size;
    } while (index!=hashfunction(n));
}

int main()
{
   TelephoneDict t;
    int choice;
    do
    {
        cout<<"****MENU****"<<endl;
        cout<<"1. Insertion of a value in the hashtable"<<endl;
        cout<<"2. Searching a value in the hashtable"<<endl;
        cout<<"3. Updating a value in the hashtable"<<endl;
        cout<<"4. Deletion of a value in the hashtable"<<endl;
        cout<<"5. Displaying the hashtable"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter the telephone number: "<<endl;
                long long int teleno;
                cin>>teleno;
                cout<<"Enter the id: "<<endl;
                int id;
                cin>>id;
                t.createRecord(teleno,id);
                break;
            case 2:
                cout<<"Enter the telephone number: "<<endl;
                long long int teleno1;
                cin>>teleno1;
                t.searchRecord(teleno1);
                break;
            case 3:
                cout<<"Enter the telephone number: "<<endl;
                long long int teleno2;
                cin>>teleno2;
                t.updateRecord(teleno2);
                break;
            case 4:
                cout<<"Enter the telephone number: "<<endl;
                long long int teleno3;
                cin>>teleno3;
                t.deleteRecord(teleno3);
                break;
            case 5:
                t.display();
                break;
            case 6:
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    } while (choice!=6);
    return 0;
}
