#include<iostream>
using namespace std;

class CTest1
{
    private:
        int iCount;
    
    public:
        CTest1()
        {
            iCount = 0;
            cout<<"Constructor\n";
        }

        ~CTest1()
        {
            cout<<"Destructor\n";
        }
};

int main()
{
    int iCount = 0;
    if(iCount == 0)
    {
        static CTest1 obj;
    }
    cout<<"End of Main\n";
    return 0;
}