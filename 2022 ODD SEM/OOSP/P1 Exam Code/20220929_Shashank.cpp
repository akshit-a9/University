#include <iostream>

using namespace std;

class Student
{
    private:
       int rollno[5];
       char name[5];
    public:
       void get()
       {
           for(int i=0;i<3;i++)
           {
               cout<<"Enter Roll no:\n";
               cin>>rollno[i];
               cout<<"Enter Name:\n";
               cin>>name[i];
           }
       }
       void display()
       {
           for (int i = 0 ; i< 2; i++) 
           {
               cout<<"\nRollno is \n"<<rollno[i];
               cout<<"\nName is \n"<<name[i];
           }
       }
};
class CSE: public Student
{
    private:
       int Subject;
    public:
       void get_subject()
       {
           cout<<"Enter the Subject:";
           cin>>Subject;
       }
       void disp_subject()
       {
           cout<<"Subject is "<<Subject;
       }
};
class CIVIL: public Student
{
    private:
       int Subject;
    public:
       void get_subject()
       {
           cout<<"Enter the Subject:";
           cin>>Subject;
       }
       void disp_subject()
       {
           cout<<"Subject is "<<Subject;
       }
};
class ECE: public Student
{
    private:
       int Subject;
    public:
       void get_subject()
       {
           cout<<"Enter the Subject:";
           cin>>Subject;
       }
       void disp_subject()
       {
           cout<<"Subject is "<<Subject;
       }
};
class Faculty: public CSE,public Civil,public ECE
{
    private:
       char subject;
       char dept;
    public:
       void get()
       {
           cout<<"Enter the subject handled by Faculty:";
           cin>>subject;
           cout<<"Enter the dept handled by Faculty:";
           cin>>dept;
       }
       void disp()
       {
           cout<<"Subject handled by Faculty "<<subject;
           cout<<"Department handled by Faculty "<<dept;
       }
};
class Placement: public CSE, public Civil, public ECE
{
    private:
       int Package;
       char dept;
    public:
       void get()
       {
           cout<<"Enter the Package:";
           cin>>Package;
           cout<<"Enter the dept:";
           cin>>dept;
       }
       void disp()
       {
           cout<<"Package is "<<Package;
           cout<<"Department is "<<dept;
       }
};
class Exam: public Faculty
{
    private:
       int attendance;
    public:
       void get()
       {
           cout<<"Enter the attendnace";
           cin>>attendance;
       }
       void disp()
       {
           cout<<"Attednace is "<<attendance;
       }
};

int main()
{
    Student s1[5];
    for(int i =0;i<3;i++)
    {
        s1[i].get();
    }
    // for(int i =0;i<5;i++)
    // {
    //     s1[i].display();
    // }
    
    return 0;
}