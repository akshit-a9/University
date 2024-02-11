#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

template<class X>
class Ak
{
    struct cb
    {
        int cap;
        X*arr;
        int top = -1;
    };

    cb*s;

    public:
    Ak(int cap)
    {
        s = new cb;
        s -> cap = cap;
        s -> arr = (X*)calloc(s ->cap, sizeof(X));
    }

    void push(X data)
    {
        if(s -> top <= s -> cap)
            s -> arr[++s -> top] = data;
        else cout<<"\n Stack is Full";
    }

    void viewall()
    {
        int i;
        for(i = 0; i<=s -> cap-1; i++)
        {
            cout<<"\n"<<s ->arr[i];
        }
        cout<<endl<<endl;
    }

    void pop()
    {
        if(s -> top != -1)
            cout<<"\n"<<s->arr[s->top--];
        else cout<<"\nStack is Empty";
    }

    void popall()
    {
        for(int i = 0; i<=s -> cap-1; i++)
        pop();
    }
};

int main()
{
    Ak<int> stack(10);
    for(int i = 0; i<10; i++)
    {
        stack.push(rand());
    }

    for(int i = 0; i<11; i++)
    {
        stack.pop();
    }

    for(int i = 0; i<10; i++)
    {
        stack.push(rand());
    }

    cout<<endl;
    stack.viewall();
    stack.popall();
    return 0;
}