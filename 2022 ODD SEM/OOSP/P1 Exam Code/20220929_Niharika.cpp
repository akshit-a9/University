// #include<iostream>
// using namespace std;
// class student
// {    
//     public:
//     int rollno;
//     string name;
// };
// class cse: public student
// {
//     public:
//     int marks;
//     string fac="KAMLESH";
//     void csee(int marks)
//     {
//         this->marks=marks;
//         cout<<"marks"<<this->marks<<endl;
//     }
// };
// class civil:public student
// {  
//    public:
//    int marks;
//    string fac="SURESH";
//    void civv(int marks)
//     {
//         this->marks=marks;
//         cout<<"marks"<<this->marks<<endl;
//     }
// };
// class ece:public student
// {   
//     public:
//     int marks;
//     string fac="RAMESH";
//     void ecee(int marks)
//     {
//         this->marks=marks;
//         cout<<"marks"<<this->marks<<endl;
//     }
// };
// class faculty:public civil,public cse,public ece
// {   
//     public:
//     void getfacultyname()
//     {
//        cout<<"FACULTY NAME : "<<cse::fac<<endl;
//     }
// };
// class placement:public cse,public civil
// {   
//     int avg;
//     public:
//     void setplacement(int avg)
//     {
//         this->avg=avg;
//     }
//     void getplacement()
//     {
//         cout<<"AVG: "<<avg<<endl;
//     }
// };
// class exam:public faculty
// {
//      void displaymarks()
//      {
//         cout<<"MARKS:"<<cse::marks<<endl;
//         cout<<"MARKS:"<<ece::marks<<endl;
//         cout<<"MARKS:"<<civil::marks<<endl;
//      }
// };
// int main(int argc, char const *argv[])
// {
//      student s[5];
//      for (int i = 0; i < 5; i++)
//      {  
//         cout<<"Enter the name of student "<<i+1<<endl;
//         cin>>s[i].name;
//      }
//      for (int i = 0; i < 5; i++)
//      {
//         cout<<"Student "<<i<<" "<<s[i].name;
//      }
     
// }

#include <iostream> 
using namespace std; 
void error_check(string str) 
{ 
if(str != "India") 
throw"NOT_SAME_ERROR"; 
} 
string input_str() 
{ 
string str; 
cout<<"Enter the string: "; 
cin>>str; 
try 
{ 
error_check(str); 
} 
catch(...) 
{ 
cout<<"Error: String Not equal to India"; 
exit(1); 
} 
return str; 
} 
int main() 
{ 
string str; 
str=input_str(); 
cout<<"Program executed successfully!"<<endl; 
return 0; 
}