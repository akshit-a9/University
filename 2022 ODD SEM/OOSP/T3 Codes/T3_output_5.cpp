#include <iostream>
using namespace std;

class CTest
{
    mutable int x;
    public:
        CTest(int x)
        {
            cout<<(this -> x = x++);
        }
};

int main()
{
    const CTest obj (10);
}