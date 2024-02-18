//Autokey Cipher
#include <iostream>
#include <string>
using namespace std;

int main(){
    string msg, key, enc, dec;
    cout<<"Enter the message:"<<endl;
    cin>>msg;
    cout<<"Enter the key:"<<endl;
    cin>>key;
    for(int i=0; i<msg.length(); i++){
        key[i+1]=msg[i];
        if(isupper(msg[i]) && isupper(key[i])){
            enc+=char((int(msg[i])+int(key[i])-65)%26+65);
        }
        if(islower(msg[i]) && islower(key[i])){
            enc+=char((int(msg[i])+int(key[i])-97)%26+97);
        }
    }
    cout<<"Encrypted message is: "<<enc<<endl;
    for(int i=0; i<msg.length(); i++){
        key[i+1]=msg[i];
        if(isupper(enc[i]) && isupper(key[i])){
            dec+=char((int(enc[i])-int(key[i])-65)%26+26+65);
        }
        if(islower(enc[i]) && islower(key[i])){
            dec+=char((int(enc[i])-int(key[i])-97)%26+26+97);
        }
    }
    cout<<"Decrypted message is: "<<dec<<endl;
    return 0;
}