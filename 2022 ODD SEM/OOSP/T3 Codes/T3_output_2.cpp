#include <iostream>
#include <exception>
using namespace std;

class CBase
{

};

class CDerived : public CBase
{

};

int main()
{
    CDerived obj;

    try
    {
        throw obj;
    }

    catch(CBase obj)
    {
        cout<<"Caught CBase";
    }
    catch(CDerived obj)
    {
        cout<<"Caught CDerived";
    }
    catch(...)
    {
        cout<<"Caught Exception";
    }

    return 0;
}