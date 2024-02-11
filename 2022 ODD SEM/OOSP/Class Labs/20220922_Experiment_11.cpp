//EXPERIMENT 18 FROM THE COURSE DESCRIPTION (Class hiearchy shown in a figure.)

#include<iostream>
#include<string>
using namespace std;


class Staff
{
    public:
        int code;
        string name;

        void setdata()
        {
            int i;
            string j;
            cout<<"Input from the base class"<<endl;
            cout<<"Enter the Staff Code : "<<endl;
            cin>>i;
            cout<<"Enter the Staff Name : "<<endl;
            cin>>j;
            code = i;
            name = j;
        }
};

class Teacher : public Staff
{
    public:
        string subject;
        string publication;

        void setdata()    //METHOD OVERRIDING
        {
            int i;
            string a, b, c;
            cout<<"Input from the derived code : "<<endl;
            cout<<"Enter the Teacher's staff Code : "<<endl;
            cin>>i;
            cout<<"Enter the Teacher's staff Name : "<<endl;
            cin>>a;
            cout<<"Enter the Teacher's subject : "<<endl;
            cin>>b;
            cout<<"Enter the Teacher's publication : "<<endl;
            cin>>c;

            code = i;
            name = a;
            subject = b;
            publication = c;
        }

        void putdata()
        {
            cout<<"Teacher Details : "<<endl;
            cout<<"Staff Code : "<<code<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Subject : "<<subject<<endl;
            cout<<"Publication : "<<publication<<endl;
        }           
};

class Officer : public Staff
{
    public:
        int grade;

        void setdata()    //METHOD OVERRIDING
        {
            int i, j;
            string a;
            cout<<"Enter the Officer's staff Code : "<<endl;
            cin>>i;
            cout<<"Enter the Officer's Name : "<<endl;
            cin>>a;
            cout<<"Enter the Officer's grade :"<<endl;
            cin>>j;

            code = i;
            name = a;
            grade = j;
        }

        void putdata()
        {
            cout<<"Officer's Details : "<<endl;
            cout<<"Staff Code : "<<code<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Grade : "<<grade<<endl;        
        }
};

class Typist : public Staff
{
    public:
        int speed;
};

class Regular : public Typist
{
    public:
         void setdata(int s)    //METHOD HIDING
        {
            int i;
            string a;
            cout<<"Enter the Typist's staff Code : "<<endl;
            cin>>i;
            cout<<"Enter the Typist's Name : "<<endl;
            cin>>a;

            code = i;
            name = a;
            speed = s;
        }
       
        void putdata()
        {
            cout<<"Regular Typist's Details : "<<endl;
            cout<<"Staff Code : "<<code<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Speed : "<<speed<<endl;        
        }
        
};

class Casual : public Typist
{
    public:
        int daily_wage;

        void setdata(int s, int wage)    //METHOD HIDING
        {
            int i;
            string a;
            cout<<"Enter the Typist's staff Code : "<<endl;
            cin>>i;
            cout<<"Enter the Typist's Name : "<<endl;
            cin>>a;

            code = i;
            name = a;
            speed = s;
            daily_wage = wage;
        }
        
        void putdata()
        {
            cout<<"Casual Typist's Details : "<<endl;
            cout<<"Staff Code : "<<code<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Speed : "<<speed<<endl;    
            cout<<"Daily Wage : "<<daily_wage<<endl;    
        }
};

int main()
{
    Teacher t1;
    Officer o1;
    Regular r1;
    Casual c1;

    int choice;
    
        cout<<"WHAT STAFF DO YOU WANT TO ENTER THE DETAILS OF?"<<endl;
        cout<<"1 for Teacher"<<endl<<"2 for Officer"<<endl<<"3 for Regular Typist"<<endl<<"4 for Casual Typist"<<endl;
        cin>>choice;

        if(choice == 1)
        {
            t1.setdata();
            t1.putdata();
        }
        else if(choice == 2)
        {
            o1.setdata();
            o1.putdata();
        }
        else if(choice == 3)
        {
            r1.setdata(78);
            r1.putdata();
        }
        else if(choice == 4)
        {
            c1.setdata(62, 800);
            c1.putdata();
        }
    
}

