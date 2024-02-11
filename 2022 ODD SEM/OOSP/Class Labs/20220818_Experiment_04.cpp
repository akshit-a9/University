//Class employee which stores data about a company's employees. Increment salary by 25% upon confirmation of promotion. 

#include<iostream>
#include<string>
using namespace std;

class employee
{
    private:
        int num, c_rank, c=0, choice;
        string name, dob;
        double salary;
    public:
        employee()
        {
            num = 0;
            name = "";
            dob = "";
            c_rank = 0;
            salary = 0.0;
        }

        void check()
        {
            cout<<"Press 1 if you hired an employee";
            cin>>choice;
            if(choice == 1)
            c = 1;
            else c = 0;

            if(c==1)
            {
                cout<<"Enter employee details in order: \nName \nNumber \nDate of Birth (DD-MM-YYYY) \nRank \nSalary : "<<endl;
                cin>>name>>num>>dob>>c_rank>>salary;
            }
        }

        void print()
        {
            cout<<"Employee details : "<<endl<<name<<endl<<num<<dob<<endl<<c_rank<<endl<<salary;
        }

        void update()
        {
            c_rank = c_rank+1;
            salary = salary*1.25;
        }
};

int main()
{
    int choice1, choice2;
    employee e1;

    cout<<"Enter 1 if you are an employee";
    cin>>choice1;
    if(choice1 == 1)
    {
        e1.print();
    }
    else
    {
        e1.check();
        e1.print();
        cout<<"Enter 1 to promote the employee";
        cin>>choice2;
        if(choice2 ==1)
        {
            e1.update();
            e1.print();
        }
    }
    return 0;
}