#include <iostream>
#include <string>
using namespace std;

int main()
{
    int snum, x, s, f, state, n;
    char s1,s2,sym;

    cout<<"Please enter the number of states : ";
    cin>>x;

    //no way to initialise variables according to number of alphabets, so defaulting to 2

    cout<<"Please enter the two alphabet symbols involved : ";
    cin>>s1>>s2;

    int transitions[x][3];

    cout<<"According to the following positions in the transition table, enter the values : "<<endl;

    cout<<"   "<<s1<<"  "<<s2<<endl;
    for(int i = 0; i<x; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<i<<j<<" ";
        }
        cout<<endl;
    }

    for(int i = 0; i<x; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<"Enter the state number for the position "<<i<<j<<" : ";
            cin>>snum;
            transitions[i][j] = snum;
        }
        cout<<endl;
    }

    cout<<"The transition table entered is as follows: "<<endl;
    cout<<"  "<<s1<<" "<<s2<<endl;
    for(int i = 0; i<x; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<transitions[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Enter the initial state : ";
    cin>>s;
    cout<<"Enter the final state : ";
    cin>>f;

    state = s;
    string st;

    cout<<"Enter the string : ";
    cin>>st;
    cout<<endl;
    n = st.length();

    for(int i=0; i<n; i++)
        {
            sym=st[i];
            for(int j=0; j<x; j++)
            {
                if(sym==s1 && state==transitions[j][0])
                {
                    state=transitions[j][1];
                    break;
                }
            else if( sym==s2 && state==transitions[j][0])
                {
                    state=transitions[j][2];
                    break;
                }
            }
            cout<<"At "<<sym<<", transitioned to state "<<state<<"."<<endl;
        }

    if(state==f)
    {
        cout<<endl<<"Since at the end of string, we are at state "<<f<<", The string is accepted!"<<endl;
    }
    else
    {
        cout<<endl<<"The string was not accepted."<<endl;
    }

    return 0;
}