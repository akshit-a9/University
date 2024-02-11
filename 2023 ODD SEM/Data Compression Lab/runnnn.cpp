#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string st = "", otp;
    char a;
    int count;

    ifstream fin;
     fin.open("data.txt");
     getline(fin,st);
     int n = st.length();
    fin.close();

    ofstream fout;
    fout.open("output.txt");
    for(int i=0;i<n;i++)
    {
        count = 1;
        while(1<n-1 && st[i]==st[i+1])
        {
            count++;
            i++;
        }
        fout<<st[i]<<";"<<count<<endl;
    }
    fout.close();

    ifstream finn;
        finn.open("output.txt");
        while(getline(finn,otp))
        {
            cout<<otp<<endl;
        }
    finn.close();

    return 0;
}