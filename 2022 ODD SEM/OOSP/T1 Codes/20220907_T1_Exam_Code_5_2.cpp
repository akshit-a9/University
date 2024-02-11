#include<iostream>
using namespace std;

class CTest2
{
    private:
        int iCount;
        const int iValue = 10;

    public:
        CTest2(int x)
        {
            iCount = x;
        }

        void Display() const
        {
            iCount +=5;
            cout<<iCount;
            cout<<iValue;
        }
};

int main()
{
    CTest2 obj(5);
    obj.Display();
    return 0;
}