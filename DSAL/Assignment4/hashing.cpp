
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
    int n;
    int id;
    int index;
    long int telephoneno;
    public:
    int hashfunction(int n)
    {
    
        index=n%10;
        return index;
    }
    void createRecord();
    void searchRecord();
    void deleteRecord();
    void updateRecord();


};
void TelephoneDict::createRecord()
{  
    // cout<<"Enter the number of entries: "<<endl;
    // cin>>n;
        int newindex;
        int i=1;
        cout<<"Enter the id: "<<endl;
        cin>>id;
        cout<<"Enter the corresponding telephone number: "<<endl;
        cin>>telephoneno;
        int value=hashfunction(id);
        //int value=id%10;
        for (int j=0;j<10;j++)
        {   
            if(h[value].key==0)
            {
            h[value].key=id;
            h[value].teleno=telephoneno;
            break;
            }
            else{
                value=(value+i)%10;
                i++;
                if(i==11)
                {
                    break;
                }
            }
        }       
}
void TelephoneDict::searchRecord()
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
            // h[newindex].key=id;
            // h[newindex].teleno=telephoneno;
            cout<<"Record found!"<<endl;
            cout<<"Following is the result:"<<endl;
            cout<<h[newindex].key<<":"<<h[newindex].teleno<<endl;
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
            else{
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
int main()
{
   
}

