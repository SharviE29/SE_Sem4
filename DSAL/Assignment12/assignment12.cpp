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
    private:
        fstream file;
    public:
        void create();
        void delete_record();
        void display();

};
void Fileops::create()
{   
    Student s;
    char ch='y';
    file.open("student.txt",ios::in|ios::out|ios::binary);
    do{
        cout<<"Enter Name: ";
        cin>>s.name;
        cout<<"Enter Roll: ";
        cin>>s.roll;
        cout<<"Enter Division: ";
        cin>>s.division;
        cout<<"Enter Address: ";
        cin>>s.address;
        file.write((char*)&s,sizeof(s));
        cout<<"Do you want to continue?(y/n): ";
        cin>>ch;
    }while(ch=='y');
    file.close();
}
void Fileops::delete_record()
{   
    int roll;
    cout<<"Enter the roll number of student to be deleted: ";
    cin>>roll;
    file.open("student.txt",ios::in|ios::out,ios::binary);
    file.seekg(0,ios::beg);
    file.close();
    while(!file.eof())
    {
        file>>roll;
        if(roll!=roll)
        {
            file<<roll<<" ";
        }
    }
    file.close();
    file.open("student.txt",ios::out);
    file.close();
    file.open("temp.txt",ios::in);
    while(!file.eof())
    {
        file>>roll;
        file<<roll<<" ";
    }
    file.close();
}


int main()
{
    int ch;
    Fileops f;
    Student s;
    do
    {
        cout<<"1. Add student"<<endl;
        cout<<"2. Delete student"<<endl;
        cout<<"3. Search student"<<endl;
        cout<<"4. Display student"<<endl;
        cout<<"5. Display all student"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter the details of student: "<<endl;
                cout<<"Roll: ";
                cin>>s.roll;
                cout<<"Name: ";
                cin>>s.name;
                cout<<"Division: ";
                cin>>s.division;
                cout<<"Address: ";
                cin>>s.address;
                f.add(s);
                break;
            case 2:
                f.delete_record();
                break;
            case 3:
                f.search();
                break;
            case 4:
                f.display();
                break;
            case 5:
                f.display_all();
                break;
            case 6:
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(ch!=6);
    return 0;
}

