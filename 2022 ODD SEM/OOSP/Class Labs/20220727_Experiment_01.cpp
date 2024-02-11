//We create a class that keeps basic account info. Also, we can transfer money between two accounts.

#include<iostream>
using namespace std;

class acc
{
    private:
        
        int balance;
    public:
        
        void display()
        {cout<<"\nThe balance is : " << balance ;}
        
        void imp_amt(int amt)
        {balance = amt;}

        acc transfer (acc obj1, int amt)
        {
            balance = balance - amt;
            obj1.balance = obj1.balance + amt;
            return obj1;
        }
};

int main()
{
    acc a1, a2;
    cout<<"Balance Transfer : ";
    a1.display();
    a2.display();

    int x, y;

    cout<<"\n Enter the amount(s) for a1 and a2 : ";
    cin>>x>>y;
    a1.imp_amt(x);
    a2.imp_amt(y);

    a2 = a1.transfer(a2, 600);

    cout<<"After Transfer : ";
    a1.display();
    a2.display();

    return 0;
}