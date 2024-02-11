// // //Write programs to show the use of Friend Class, Inline function and Constant Function
// // //Note for friend class make a class frend of 2 classes. 

// // #include<iostream>
// // using namespace std;

// // class B;

// // class A
// // {
// //     private:
// //         float x;
// //     public:
// //     A()
// //     {
// //         x = 3.14;
// //     }
// //     friend class B;
// //     friend void printa();
// // };

// // class B
// // {
// //     private:
// //         float y;
// //     public:
// //         B()
// //         {
// //             y = 6.28;
// //         }
// //         void print(A i)
// //         {
// //             cout<<endl<<i.x;
// //         }
// //         friend class A;
// // };

// // void printa(B j)
// //     {
// //         cout<<j.y;
// //     }

// // int main()
// // {
// //     A obj1;
// //     B obj2;
// //     obj2.print(obj1);
// //     printa(obj2);
// // }



// Program to demonstrate friend class, inline and constant function.
//The result we have to get is : (a/b*c), where a, b and c are squared values of the input

#include<iostream>
using namespace std;

class C;

class A
{
    private:
        float a1;
    public:
        A(float a)
        {
            a1 = a;
        }

        friend class C;
};

class B
{
    private:
        float a2;
    public:
        B(float a)
        {
            a2 = a;
        }

        friend class C;
};

class C
{
    private:
        float a3;
    public:
        C(float a)
        {
            a3 = a;
        }

        float calculate(C obj1, A obj2, B obj3) const
        {
            float num;
            num = obj2.a1 / obj3.a2 * obj1.a3;
            return num;
        }
};

inline float setval(float a)
{
    float sq;
    sq = a*a;
    return sq;
}

int main()
{
    float p, q, r;
    float num;
    cout<<"Enter the three operands"<<endl;
    cin>>p>>q>>r;
    p = setval(p);
    q = setval(q);
    r = setval(r);
    
    C obj_c(r);
    A obj_a(p);
    B obj_b(q);

    num = obj_c.calculate(obj_c, obj_a, obj_b);
    cout<<"The result is : "<<num;
}


// #include <iostream>
// using namespace std;

// template<class T>
// class Base {
//     protected:
//         T val;

//     public:
//         void setVal(T a)
//         {
//             val = a;
//         }
// };

// template<class T>
// class Derived : public Base<T> {
//     public:
//         void setVal (T b)
//         {
//              Base<T>::val=b;
//         }
        
//         void getVal()
//         {
//             cout<<Base<T>::val;
//         }
// };
// int main()
// {
//     Derived<int> a;
//     a.setVal(4);
//     a.getVal();
//     return 0;
// }


#include<iostream>
using namespace std;

template<class T>
class calculator
{
    public:
        T val1, val2;

        T add(T a, T b)
        {
            T c;
            c = a+b;
            return c;
            cout<<"Base \n";
        }
};

template<class T>
class scientifi : public calculator<T>
{
    public:
        T val3;
        using calculator<T> :: add;
        T add(T a, T b, T c)
        {
            T d;
            d = a+b+c;
            return d;
            cout<<"Derived \n";
        }
};

int main()
{
    int a, b, c;
    a = 3;
    b = 5;
    c = 12;

    scientifi<int> obj;

    cout<<obj.add(a,b);
    cout<<endl<<endl<<obj.add(a,b,c);
}