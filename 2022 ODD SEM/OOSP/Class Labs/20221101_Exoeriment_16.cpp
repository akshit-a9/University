//Not to be done in lab copy

#include <iostream>
#include<cstring>
using namespace std;



template <typename T, typename u> u myMax(T x, u y)
{
return (x > y) ? x : y;
}

template<>
char*myMax<char* >(char*x, char*y){return strcmp(x,y)>0?x:y;}                    
int main()
{
char*s1=new char[6], *s2=new char[6] ;
strcpy(s1,"black");
strcpy(s2,"white");
cout << myMax<int,double>(3, 7.5) << endl; // Call myMax for int
cout << myMax<double,double>(3.0, 7.0) << endl; 
cout << myMax<char>('g', 'e')<< endl; ; 
cout << myMax<char*>(s1,s2) << endl; 
return 0;
}

 