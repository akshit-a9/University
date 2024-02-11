//Reverse of integer value
//Method-02 : Pointers

#include <iostream>
using namespace std;

class BCD
{
    private:
        int n, m;
        int *p;
        int i = 0;
    public:
        void set (int num)
        { 
            n = num;
            m = n;
        }

        void count()
        {
            while(n>0)
            {
                n = n/10;
                i++;
            }
        }

        void reverse()
        {
            p = (int *) malloc (i * sizeof(int));
            for(int j = 0; j<1; j++)
            {
                *(p+j) = m%10;
                m = m/10;
            }
        }

        void print()
        {
            cout<<"Reverse : ";
            for(int j = 0; j<i; j++)
            cout<< *(p+j);
        }
};

int main()
{
    BCD obj1;
    int a;
    cout<<"Enter an integer : ";
    cin>>a;
    obj1.set(a);
    obj1.count();
    obj1.reverse();
    obj1.print();

    return 0;
}