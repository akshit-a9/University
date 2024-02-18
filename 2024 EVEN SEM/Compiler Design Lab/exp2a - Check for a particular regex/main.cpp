//DFA for the string regular expression a+(aa)*b
#include <iostream>
#include <string.h>
using namespace std;

int main() 
{
    int n, state=0;
    int trans_table[6][3]={ 0, 1, 2,
                            1, 3, 5,
                            2, 5, 5,
                            3, 4, 2,
                            4, 3, 5,
                            5, 5, 5};
    string st;
    cout<<"Enter the string:"<<endl;
    cin>>st;
    n=st.length();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<6; j++)
        {
            if(st[i]=='a' && state==trans_table[j][0])
            {
                state=trans_table[j][1];
                break;
            } 
            else if( st[i]=='b' && state==trans_table[j][0])
            {
                state=trans_table[j][2];
                break;
            }
        }
        cout<<"At "<<st[i]<<", transitioned to state : "<<state<<endl;
    }
    if(state==1 || state ==2)
    {
        cout<<endl<<"At the end of the string, we are at state "<<state<<endl<<"Since it is a final state, the string is accepted!";
    }
    else
    {
        cout<<endl<<"At the end of the string, we are at state "<<state<<endl<<"Not being a final state, the string is NOT accepted!";
    }
    cout<<endl;

    return 0;
}