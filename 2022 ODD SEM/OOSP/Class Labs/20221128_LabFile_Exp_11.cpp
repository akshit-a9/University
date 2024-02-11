#include<iostream>
using namespace std;

class Person
{
    string name = "Akshit";

    public:
        virtual void fun() = 0;
        string getname()
        {
            return name;
        }
};

class Faculty : public Person
{
    int salary = 45000;
    public:
        void fun()
        {
            cout<<"fun() called inside faculty"<<endl;
            cout<<"Salary : "<<salary<<endl;
        }
};

class Student : public Person
{
    int roll_no = 211435;
    
    public:
        void fun()
        {
            cout<<"void() called inside student"<<endl;
            cout<<"Roll No: "<<roll_no<<endl;
        }
};

int main(void)
{
    Student s;
    s.fun();
    Faculty f;
    f.fun();
    return 0;
}