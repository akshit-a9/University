#include <iostream>
#include <exception>
using namespace std;

void Test (int x, char ch) throw ()
{
    if(x==0) throw x;
    if(ch=='a') throw ch;
}

int main()
{
    try
    {
        Test(0, 'A');
        Test(1, 'a');
    }
    catch(int x)
    {
        cout<<"Exception!\n";
    }

    catch(...)
    {
        cout<<"Wow! Exception?";
    }

    return 0;
}