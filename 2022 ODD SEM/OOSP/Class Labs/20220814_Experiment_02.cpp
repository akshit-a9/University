//Reverse of integer value
//Method-01 : Arrays

#include <iostream>
using namespace std;

class BCD
{
    private:
        int n;
        int arr[6];
        int i = 0;
    public:
        void set (int num)
        { n = num;}

        void reverse()
        {
            while (n>0)
            {
                arr[i] = n %10;
                n = n/10;
                i++;
            }
        }

        void print()
        {
            cout<<"Reverse : ";
            for(int j = 0; j<i; j++)
            cout<< arr[j];
        }
};

int main()
{
    BCD obj1;
    int a;
    cout<<"Enter an integer : ";
    cin>>a;
    obj1.set(a);
    obj1.reverse();
    obj1.print();

    return 0;
}