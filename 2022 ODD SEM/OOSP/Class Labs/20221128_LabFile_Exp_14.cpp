#include<iostream>
using namespace std;

template<class T>
class calculator
{
    public:
    void add(T a, T b)
    {
        cout<<a+b<<endl;
    }

    void sub(T x, T y)
    {
        cout<<x-y<<endl;
    }
};

template<class T>
class scientifi : public calculator <T>
{
    public:
        using calculator<T> ::add;
        void add(T m, T n, T o)
        {
            cout<<m+n+o<<endl;
        }
};

int main()
{
    scientifi<float> obj;
    obj.add(69.69, 99.99, 77.63);
    obj.add(69, 99);
    return 0;
}
