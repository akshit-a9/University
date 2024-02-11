#include <iostream>
using namespace std;

class CTest
{
    static int i;
    
    public:
        CTest()
        {
            i++;
        }

        static int j;
        static void init(int x)
        {
            i = x;
        }
        void show()
        {
            cout<<i;
        }
};

int CTest :: i = 100;

int main()
{
    CTest :: init(10);
    CTest obj;

    obj.show();
    return 0;
} 