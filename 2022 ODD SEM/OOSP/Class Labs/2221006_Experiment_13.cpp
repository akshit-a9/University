//

// #include<iostream>
// using namespace std;

// class Base
// {
// int x;
// public:
// 	virtual void fun() = 0;
// 	int getX() { return x; }
// };

// // This class inherits from Base and implements fun()
// class Derived: public Base
// {
// 	int y;
// public:
// 	void fun() { cout << "fun() called"; }
// };

// int main(void)
// {
// 	Derived d;
// 	d.fun();
// 	return 0;
// }


// #include<iostream>
// using namespace std;

// class Base
// {
// public:
// 	virtual void show() = 0;
// };

// class Derived: public Base
// {
// public:
// 	void show() { cout << "In Derived \n"; }
// };

// int main(void)
// {
// 	Base *bp = new Derived();
// 	bp->show();
// 	return 0;
// }

// #include<iostream>
// using namespace std;

// class Person
// {
//     public:
//         int id;
//         string name;
//         string f_name;
//         string address;

//         virtual void get(string a, string b, int c) = 0;

//         void display()
//         {
//             cout<<"Details of the Person:"<<endl;
//             cout<<"Name : "<<name;
//             cout<<"Father's Name : "<<f_name;
//             cout<<"Address : "<<address;
//             cout<<"ID : "<<id;
//         }
// };

// class Student : public Person
// {
//     public:
//         int CGPA;
//         string grade;

//         void get(string a, string b, int c)
//         {
//             cout<<"Enter the details : "<<endl;
//             cout<<"Enter the Father's Name : ";
//             cin>>f_name;
//             cout<<"Enter the Address : ";
//             cin>>address;
//             cout<<"Enter the CGPA";
//             cin>>CGPA;
//             name = a;
//             grade = b;
//             id = c;
//         }

//         void display()
//         {
//             cout<<"Details of the Student : "<<endl;
//             cout<<"Name : "<<name;
//             cout<<"Father's Name : "<<f_name;
//             cout<<"Address : "<<address;
//             cout<<"ID: "<<id;
//             cout<<"CGPA : "<<CGPA;
//             cout<<"Grade : "<<grade;
//         }
// };


// class Faculty : public Person
// {
//     public:
//         int salary;
//         string initials;

//         void get(string a, string b, int c)
//         {
//             cout<<"Enter the details : "<<endl;
//             cout<<"Enter the Father's Name : ";
//             cin>>f_name;
//             cout<<"Enter the Address : ";
//             cin>>address;
//             cout<<"Enter the Salary";
//             cin>>salary;
//             name = a;
//             initials = b;
//             id = c;
//         }

//         void display()
//         {
//             cout<<"Details of the Student : "<<endl;
//             cout<<"Name : "<<name;
//             cout<<"Father's Name : "<<f_name;
//             cout<<"Address : "<<address;
//             cout<<"ID: "<<id;
//             cout<<"Salary : "<<salary;
//             cout<<"Initials : "<<initials;
//         }
// };

// // int main()
// // {
    
// // }


#include<iostream>
using namespace std;
int main()
{
register int i;
int *ptr = &i; 
cout << *ptr;
return 0;
}


