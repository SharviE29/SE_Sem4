/*
Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use
sequential file to main the data.
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
class Student
{
   public:
        int roll;
        string name;
        string division;
        string address;

    public:
        Student()
        {
            roll=0;
            name="";
            division="";
            address="";
        }  
        Student(int roll, string name,string division, string address)
        {
            this->roll=roll;
            this->name=name;
            this->division=division;
            this->address=address;
        }
};

class Fileops
{
    public:
    void create();
    void display();
    void deleterecord();
};

void Fileops::create()
{
    char ch;
    ofstream fout;
    Student s;
    fout.open("student.txt",ios::out|ios::binary);
    do
    {
       cout<<"Enter the name of the student: ";
       cin>>s.name;
       cout<<"Enter the roll number of the student: ";
       cin>>s.roll;
       cout<<"Enter the division of the student: ";
       cin>>s.division;
       cout<<"Enter the address of the student: ";
       cin>>s.address;
       fout.write((char*)&s,sizeof(s));
       cout<<"Do you want to enter more records?(y/n): ";
         cin>>ch;
    }while(ch=='y'||ch=='Y');
            
    fout.close();
}

void Fileops::display()
{
    ifstream fin;
    Student s;
    fin.open("student.txt",ios::in|ios::binary);
    while(fin.read((char*)&s,sizeof(s)))
    {  
        if(fin.eof())
        {
            break;
        }
        if(fin.fail())
        {
            cout<<"Error in reading file"<<endl;
            break;
        }
        if(s.roll!=-1)
        {
            cout<<"Name: "<<s.name<<endl;
            cout<<"Roll number: "<<s.roll<<endl;
            cout<<"Division: "<<s.division<<endl;
            cout<<"Address: "<<s.address<<endl;
        }
    }
    fin.close();
}
void Fileops::deleterecord()
{
    fstream f;
    Student s;
    int roll;
    f.open("student.txt",ios::in|ios::out|ios::binary);
    cout<<"Enter the roll number of the student to be deleted: ";
    cin>>roll;
    while(f.read((char*)&s,sizeof(s)))
    {
        if(f.eof())
        {
            break;
        }
        if(f.fail())
        {
            cout<<"Error in reading file"<<endl;
            break;
        }
        if(s.roll==roll)
        {
            s.roll=-1;
            f.seekp(-1*sizeof(s),ios::cur);
            f.write((char*)&s,sizeof(s));
            break;
        }
    }
    f.close();
}

int main()
{
    int choice;
    Fileops f;
    do
    {
        cout<<"1. Create a file"<<endl;
        cout<<"2. Display the file"<<endl;
        cout<<"3. Delete a record"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                f.create();
                break;
            case 2:
                f.display();
                break;
            case 3:
                f.deleterecord();
                break;
            case 4:
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(choice!=4);
    return 0;
}