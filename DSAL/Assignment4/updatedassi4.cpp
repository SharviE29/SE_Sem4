/*
Consider telephone book database of N clients. Make use of a hash table
implementation to quickly look up client‘s telephone number. Make use of two
collision handling techniques and compare them using number of comparisons
required to find a set of telephone numbers (use linear probing with replacement and
without replacement)
*/

#include<iostream>
#define size 10
using namespace std;
class HashEntry
{
    public:
    long long int teleno;
    string name;

    public:
    HashEntry()
    {
        teleno=0;
        name="";
    }
    HashEntry(long long int teleno,string name)
    {
        this->teleno=teleno;
        this->name=name;
    }
    friend class Hashtable ;
};
class HashTable
{
    private:
    HashEntry h[size];
    int elements;

    public:
    HashTable()
    {
        elements=0;
        for(int i=0;i<size;i++)
        {
            h[i].teleno=0;
            h[i].name="";
        }
    }
    int hashfunction(long long int key)
    {
        return key%size;
    }
    void insert(long long int phone,string user)
    {
        int hashindex=hashfunction(phone);
        int hashindexcopy=hashindex;
        if(size==elements)
        {
            cout<<"Hash table is full";
            return ;
        }
        else{
            do{
                 if(h[hashindex].teleno==0)
                    {
                        h[hashindex].teleno=phone;
                        h[hashindex].name=user;
                        elements++;
                        break;
                    }
                else
                {
                   hashindex=(hashindex+1)%size;
                }    
            }while(hashindex!=hashindexcopy);
        }
    }
    void insertWR(long long int phone,string user)
    {
        int hashindex=hashfunction(phone);
        int hashindexcopy=hashindex;
        if(size==elements)
        {
            cout<<"Hash table is full";
            return ;
        }
       do{
           if(h[hashindex].teleno==0)
           {
               h[hashindex].teleno=phone;
               h[hashindex].name=user;
               elements++;
               break;
           }
           else 
           {    
               int collisionindex=hashfunction(h[hashindex].teleno);
                if((hashindex!=collisionindex) && (hashindex=hashindexcopy))
                {
                     int tempteleno=h[hashindex].teleno;
                     string tempname=h[hashindex].name;
                     h[hashindex].teleno=phone;
                     h[hashindex].name=user;
                     insertWR(tempteleno,tempname);
                     break;
                }
                else
                {
                    hashindex=(hashindex+1)%size;
                }
           }
       }while(hashindex!=hashindexcopy);   
    }
    void search(long long int teleno)
    {
        int hashindex=hashfunction(teleno);
        if(elements==0)
        {
            cout<<"There are no elements present in the hash table !";
            return ;
        }
        else
        {
            int hashindexcopy=hashindex;
            do
            {
               if(h[hashindex].teleno==teleno)
               {
                   cout<<"Record found !";
                   cout<<"\n The name of the user is :"<<h[hashindex].name;
                   return ;
               }
               else
               {
                   hashindex=(hashindex+1)%size;
               }
            } while (hashindex!=hashindexcopy);    
            cout<<"Number isnt present !";
        }
    }
    void display()
    {
        for(int i=0;i<size;i++)
        {
            if(h[i].teleno!=0)
            {
                cout<<h[i].teleno<<" : "<<h[i].name<<endl;
            }
        }
    }
};
int main()
{
    HashTable h;
    HashTable h1;
    cout<<"\n With replacement"<<endl;
    h1.insertWR(233435252,"sharviendait");
    h1.display();
    cout<<"\n Without replacement"<<endl;
    h.insert(12324324,"sharvi");
    h.display();
    return 0;
}