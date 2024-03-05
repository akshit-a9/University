//implementation of playfair cipher
#include <iostream>
#include <string>
using namespace std;

int main(){
    string tb[5][5];
    string key, text, keep=" ";
    int t=0, z=65;
    cout<<"Enter the key with distinct alphabets:"<<endl;
    cin>>key;
    cout<<"Enter the plain text: "<<endl;
    cin>>text;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(t<key.length()){
                tb[i][j]=key[t];
                t++;
            }
            else{
                for(int k=0; k<key.length(); k++){
                    if(key[k]==char(z) || char(z)=='J'){
                        z++;
                    }
                    // cout<<"z: "<<char(z)<<endl;
                }
                tb[i][j]=char(z);
                z++;
            }
        } 
    }

    for(int i=0; i<text.length(); i++){
        if(text[i]==text[i+1]){
            keep+=text[i];
            keep+='X';
        }
        else{
            keep+=text[i];
        }
    }

    if((keep.length()%2) != 0 ){
        keep+='Z';
    }

    
    cout<<"Key in table:"<<endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<tb[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Paired text: "<<keep;
    return 0;
}