// // #include<iostream>
// // using namespace std;

// // class CBase
// // {
// //     public:
// //         CBase()
// //         {
// //             cout<<"Cbase\n";
// //         }
// //         ~CBase()
// //         {
// //             cout<<"Cbase Destructor\n";
// //         }
// // };

// // class CDerived : public CBase
// // {
// //     public:
// //         CDerived()
// //         {
// //             cout<<"CDerived\n";
// //         }
// //         ~CDerived()
// //         {
// //             cout<<"Cderived Destructor\n";
// //         }
// // };

// // int main()
// // {
// //     CBase *obj = new CDerived();
// //     delete obj;

// //     // CBase *obj;
// //     // CDerived ab;
// //     // obj = &ab;
// //     return 0;
// // }


// // #include<iostream>
// // using namespace std;
// // void square(int *x, int *y)
// // {
// //     *x = (*x) * --(*y);
// // }

// // int main()
// // {
// //     int num = 30;
// //     square(&num, &num);
// //     cout<<num;
// //     return 0;
// // }

// #include<iostream>
// using namespace std;
// int main()
// {
// int a[] = {10, 20, 30, 40, 50, 60};
// int *p[] = {a, a+1, a+2, a+3, a+4, a+5};
// int **pp = p;
// pp++;
// cout<<pp-p<<" "<<*pp-a<<" "<<**p<<endl;
// *pp++;
// cout<<**pp;
// return 0;
// }

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a[10];
    for (int i = 0; i<1; i++)
    {
        cout<<"Enter\n";
        cin>>a[i];
       
    }

    return 0;
}