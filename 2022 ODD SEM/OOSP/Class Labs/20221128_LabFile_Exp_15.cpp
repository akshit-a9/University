#include<iostream>
#include<exception>
#include<math.h>
using namespace std;

class calculator
{
    protected:
    int A, a, b, x;

    public:
    void set_data(int p, int q)
    {
        a = p;
        b = q;
    }

    void user_input()
    {
        cout<<"Enter 1 for add"<<endl;
        cout<<"Enter 2 for sub"<<endl;
        cin>>A;
    }

    int get_data()
    {
        if(A == 1)
        {
            cout<<"The sum is: "<< a+b <<endl;
        }
        else if (A == 2)
        {
            cout<<"The difference is : "<< a-b <<endl;
        }
        return 0;
    }
};

class scientifi : public exception, public calculator
{
    int x;

    public:
    void user_input()
    {
        cout<<"Enter 3 for log"<<endl;
        cin>>A;
        cout<<"Enter number (x): "<<endl;
        cin>>x;

        if (A == 3)
        {
            if (x >= 0)
            {
                cout<<"The log of x is :"<< log10(x) <<endl;
            }
        }
    }

    int getdata2()
    {
        return x;
    }

    const char * what() const throw()
    {
        return "Cannot do negative numbers, sorry!";
    }

    void check(scientifi z)
    {
        int x = z.getdata2();
        if (x<0)
        {
            scientifi z;
            throw z;
        }
    }
};

int main()
{
    try
    {
        scientifi s;
        s.user_input();
        s.check(s);
    }
    catch(const std::exception& z)
    {
        std::cerr << z.what() << '\n';
    }
    
}