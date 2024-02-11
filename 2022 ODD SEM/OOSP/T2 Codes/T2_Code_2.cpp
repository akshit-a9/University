#include<iostream>
using namespace std;

class CBase
{
    public: 
        virtual void Area() = 0;
};

class CDerived1 : public CBase{

};

class CDerived2 : public CDerived1
{
    void Area()
    {
        cout<<"Hello";
    }
};

int main(void)
{
    CBase *ptr;
    CDerived1 obj1;
    CDerived2 obj2;
    ptr = &obj2;
    ptr -> Area();
    return 0;
}
