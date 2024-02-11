// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int num;
    cout<<"Enter the number of nodes : ";
    cin>>num;

    int a[num][num];

    for (int i = 0; i<num; i++)
    {
        for(int j = 0; j<num; j++)
        {
            if(i == j)
            {
                a[i][j] = 0;
            }

            else a[i][j] =1000;
        }
    }

    cout<<"Enter the number of edges : ";
    int n;
    cin>>n;

    for(int i = 0; i<n; i++)
    {
        int w, x, y;
        cout<<"Enter Edge "<<i+1<<": "<<endl;
        cin>>x>>y;
        if(x == y)
        {
            cout<<"Edge Vertices cannot be of the same value"<<endl;
            break;
        }
        cout<<"Enter Weight : ";
        cin>>w;
        a[x-1][y-1] = w;
        a[y-1][x-1] = w;

    }

    for(int i = 0; i<num; i++)
    {
        for(int j = 0; j<num; j++)
        {
            if(a[i][j] != 1000){
            cout<<"  ";}
            cout<<a[i][j]<<" ";
            if(a[i][j] != 1000){
            cout<<"  ";}
            if(a[i][j] == 1000){
            cout<<" ";}
        }
        cout<<endl;
    }

    return 0;
}
