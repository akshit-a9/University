#include<iostream>
#include<string>
using namespace std;


class student
{
    public:
        string name;
        int enroll_no;
        string batch;
        int year;
        void get_student_data()
        {
            cout<<"Name :  ";
            cin>>name;
            cout<<"Enrollment No. :  ";
            cin>>enroll_no;
            cout<<"Batch :  ";
            cin>>batch;
            cout<<"Year :  ";
            cin>>year;
        }
};

class CSE : public student
{
    public:
        string subj = "CSE";

        void put_student_data()
        {
            cout<<"Name :  "<<name<<endl;
            cout<<"Enrollment No :  "<<enroll_no<<endl;
            cout<<"Batch : "<<batch<<endl;
            cout<<"Branch :  "<<subj<<endl;
            cout<<"Year :  "<<year<<endl;
        }
};

class Civil : public student
{
    public:
        string subj = "Civil";

        void put_student_data()
        {
            cout<<"Name :  "<<name<<endl;
            cout<<"Enrollment No :  "<<enroll_no<<endl;
            cout<<"Batch : "<<batch<<endl;
            cout<<"Branch :  "<<subj<<endl;
            cout<<"Year :  "<<year<<endl;
        }
};

class ECE : public student
{
    public:
        string subj = "ECE";

        void put_student_data()
        {
            cout<<"Name :  "<<name<<endl;
            cout<<"Enrollment No :  "<<enroll_no<<endl;
            cout<<"Batch : "<<batch<<endl;
            cout<<"Branch :  "<<subj<<endl;
            cout<<"Year :  "<<year<<endl;
        }
};

class Faculty : public CSE, public Civil, public ECE
{
    public:
        string f_name;

        void get_fac()
        {
            cout<<"Enter Faculty Name :  ";
            cin>>f_name;
        }
};

class Exam : public Faculty
{
    public: 
        float attendance;
        float CGPA;
        char grade = 'F';
        static int count;
    

        static void count_students()
        {
            count = count+1;
        }

        Exam()
        {
            count_students();
        }
        void getexaminfo()
        {
            cout<<"Enter the attendance :  ";
            cin>>attendance;
            cout<<"Enter the CGPA :  ";
            cin>>CGPA;
            setgrade();
        }

        void setgrade()
        {
            if(CGPA > 9.0 && CGPA <= 10)
                grade == 'A';
            else if(CGPA > 8.0 && CGPA <= 9)
                grade == 'B';
            else if(CGPA > 7.0 && CGPA <= 8)
                grade == 'C';
            else if(CGPA > 6.0 && CGPA <= 7)
                grade == 'D';
            else if(CGPA > 5.0 && CGPA <= 6)
                grade == 'E';
        }

        void put_result() const
        {
            cout<<"Faculty :  "<<f_name;
            cout<<"Attendance :  "<<attendance;
            cout<<"CGPA :  "<<CGPA;
            cout<<"Grade :  "<<grade;
        }

};
int Exam::count = 0;

int main()
{
    int choice, num;
    cout<<"Enter your choice : \n1. CSE \n2. Civil \n3. ECE"<<endl;
    cin>>choice;

    if(choice == 1)
    {
        int choice2 = 0;
        cout<<"Enter the number of students :  ";
        cin>>num;
        Exam stu[num];
        for(int i = 0; i<num; i++)
        {
            cout<<"Enter Details of student "<<i+1<<" :  "<<endl;
            stu[i].CSE::get_student_data();
            stu[i].get_fac();
            stu[i].getexaminfo();
        }

        cout<<endl<<endl;
        cout<<"Enter your choice : \n1. Get specific student details \n2. Get all student details \n3. Get Top 5 student details"<<endl;
        cin>>choice2;
        if(choice2 == 1)
        {
            int inp;
            cout<<"Enter the roll number :  ";
            cin>>inp;
            for(int i = 0; i<num; i++)
            {
                if (stu[i].CSE::enroll_no == inp)
                {
                    stu[i].CSE::put_student_data();
                    stu[i].put_result();
                }
            }
        }

        if(choice == 2)
        {
            for(int i = 0; i<num; i++)
            {
                cout<<"Student  "<<i+1<<" :  ";
                stu[i].CSE::put_student_data();
                stu[i].put_result();
            }
        }

        if(choice == 3)
        {
            for(int i = 0; i<num; i++)
            {
                cout<<"Student  "<<i+1<<" :  ";
                stu[i].CSE::put_student_data();
                stu[i].put_result();
            }
        }
    }

    if(choice == 2)
    {
        int choice2 = 0;
        cout<<"Enter the number of students :  ";
        cin>>num;
        Exam stu[num];
        for(int i = 0; i<num; i++)
        {
            cout<<"Enter Details of student "<<i+1<<" :  "<<endl;
            stu[i].Civil::get_student_data();
            stu[i].get_fac();
            stu[i].getexaminfo();
        }

        cout<<endl<<endl;
        cout<<"Enter your choice : \n1. Get specific student details \n2. Get all student details \n3. Get Top 5 student details"<<endl;
        cin>>choice2;
        if(choice2 == 1)
        {
            int inp;
            cout<<"Enter the roll number :  ";
            cin>>inp;
            for(int i = 0; i<num; i++)
            {
                if (stu[i].Civil::enroll_no == inp)
                {
                    stu[i].Civil::put_student_data();
                    stu[i].put_result();
                }
            }
        }

        if(choice == 2)
        {
            for(int i = 0; i<num; i++)
            {
                cout<<"Student  "<<i+1<<" :  ";
                stu[i].Civil::put_student_data();
                stu[i].put_result();
            }
        }

        if(choice == 3)
        {
            for(int i = 0; i<num; i++)
            {
                cout<<"Student  "<<i+1<<" :  ";
                stu[i].Civil::put_student_data();
                stu[i].put_result();
            }
        }
    }

    if(choice == 3)
    {
        int choice2 = 0;
        cout<<"Enter the number of students :  ";
        cin>>num;
        Exam stu[num];
        for(int i = 0; i<num; i++)
        {
            cout<<"Enter Details of student "<<i+1<<" :  "<<endl;
            stu[i].ECE::get_student_data();
            stu[i].get_fac();
            stu[i].getexaminfo();
        }

        cout<<endl<<endl;
        cout<<"Enter your choice : \n1. Get specific student details \n2. Get all student details \n3. Get Top 5 student details"<<endl;
        cin>>choice2;
        if(choice2 == 1)
        {
            int inp;
            cout<<"Enter the roll number :  ";
            cin>>inp;
            for(int i = 0; i<num; i++)
            {
                if (stu[i].ECE::enroll_no == inp)
                {
                    stu[i].ECE::put_student_data();
                    stu[i].put_result();
                }
            }
        }

        if(choice == 2)
        {
            for(int i = 0; i<num; i++)
            {
                cout<<"Student  "<<i+1<<" :  ";
                stu[i].ECE::put_student_data();
                stu[i].put_result();
            }
        }

        if(choice == 3)
        {
            for(int i = 0; i<num; i++)
            {
                cout<<"Student  "<<i+1<<" :  ";
                stu[i].ECE::put_student_data();
                stu[i].put_result();
            }
        }
    }
    return 0;
}