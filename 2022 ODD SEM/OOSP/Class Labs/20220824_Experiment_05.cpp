//Students in a university. Default values to be given which are then changed upon registration.

#include<iostream>
#include<string>
using namespace std;

class student
{
    private:
        string name, dept;
        int roll_no, year, sem;
        static int a; //to count the number of objects
        static double amount;
        double amt = 0.0;
    public:
        student()
        {
            name = "";
            dept = "";
            roll_no = 0;
            year = 0;
            sem = 0;
            amt = 0.0;
            a++;
        }

        void set()
        {
            cout<<"Enter the details : ";
            cin>>name>>roll_no>>dept>>year>>sem>>amt;
        }

        void print()
        {
            cout<<"Student details : "<<endl<<name<<endl<<roll_no<<endl<<dept<<endl<<year<<endl<<sem<<endl<<amt;
        }

        void update()
        {
            cout<<"Enter the updated semester and department : ";
            cin>>sem>>dept;
            print();
        }

        void addamount()
        {
            amount = amount + amt;
        }

        static void display()
        {
            cout<<"TOTAL : "<<amount;
        }
};

int student :: a = 0;

int main()
{
    int n;
    cout<<"Enter the number of students : ";
    cin>>n;

    student s[n];
    for(int i = 0; i<n; i++)
    {
        int choice1, choice2;
        cout<<"Are you registered? (Press 1)";
        cin>>choice1;
        if(choice1 == 1)
        {
            s[i].set();
            s[i].addamount();
            s[i].print();
            cout<<"Do you want to update the details of the student ? (Press 1)";
            cin>>choice2;
            if(choice2 == 1)
            {
                s[i].update();
            }
            else s[i].print();
        }
    }
    student :: display();
    return 0;
}