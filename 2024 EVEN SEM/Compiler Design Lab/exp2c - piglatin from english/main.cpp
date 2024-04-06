// convert english to pig latin
#include <iostream>
#include <string.h>
using namespace std;

string vow(string a){
    string result,key;
    key="yay";
    result = a;
    result+=key;
    return result;
}

string con(string a){
    cout<<"word is consonant"<<endl;
    string result, key, ap="";
    key="ay";
    int n=a.length();
    for(int i=0; i<n; i++){
        if(a[i]=='q' && a[i+1]=='u'){
            a[i+1]='1';
        }
        else if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' &&
            a[i+1]!='q'){
            result.append(a,i,n);
            break;
        }
        ap+=a[i];
    }
    for(int i=0; i<ap.length(); i++){
        if(ap[i]=='1'){
            ap[i]='u';
        }
    }
    result+=ap;
    result+=key;
    return result;
}

int main() {
    string wrd, ans="";
    char c;
    int i=0;
    cout<<"Please enter your word:"<<endl;
    cin>>wrd;
    if(wrd[i]=='U'|| wrd[i]=='u' && wrd[i+1]=='q' || wrd[i+1]=='Q'){
        ans=con(wrd);
    }
    else if(wrd[i]=='Y'|| wrd[i]=='y' && (wrd[i+1]!='a' || wrd[i+1]!='e' ||
        wrd[i+1]!='i' || wrd[i+1]!='o' || wrd[i+1]!='u')){
            ans=vow(wrd);
    }
    else if(wrd[i]=='a' || wrd[i]=='e' || wrd[i]=='i' || wrd[i]=='o' || wrd[i]=='u'){
        ans=vow(wrd);
    }
    else{
        ans=con(wrd);
    }
   
    cout<<"The pig latin of your word is: "<<ans<<endl;

    return 0;
}








x+(y+z)+(p+z)+u