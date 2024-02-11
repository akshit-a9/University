#include <iostream>
using namespace std;

class calculator
{
public:
    int sum(int a, int b)
    {
        return a+b;
    }
    int sum(int p, int q, int r)
    {
        return p+q+r;
    }
    int product(int a, int b)
    {
        return a*b;
    }
    int product (int p, int q, int r)
    {
        return p*q*r;
    }
};

int main()
{
    calculator calc;
    cout<<"sum(2,4) = "<<calc.sum(2,4)<<endl;
    cout<<"sum(2,4,6) = "<<calc.sum(2,4,6)<<endl;
    cout<<"product(2,4) = "<<calc.product(2,4)<<endl;
    cout<<"product(2,4,6) = "<<calc.product(2,4,6)<<endl;
    return 0;
}
