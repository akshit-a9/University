#include <iostream>
using namespace std;

void Test (const int *x)
{
    cout<<*x++;
}

int main()
{
    void (*func_ptr)(const int*);
    func_ptr = Test;
    int x = 2;
    func_ptr(&x);
    (*func_ptr)(&x);
    return 0;
}