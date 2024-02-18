//Vigenere Cypher (Polyalphabetic)
//Using same logic as Ceaser Cipher
#include <iostream>
#include <string>
using namespace std;

string v_enc(string msg, string key){
    string encr="";
    for(int i=0; i<msg.length(); i++){
        if(isupper(msg[i]) && isupper(key[i%key.length()])){
            encr+=char((int(msg[i])+int(key[i%key.length()])-65)%26+65);
        }
        if(islower(msg[i]) && islower(key[i%key.length()])){
            encr+=char((int(msg[i])+int(key[i%key.length()])-97)%26+97);
        }
    }
    return encr;
}

string v_dec(string msg, string key)
{
    string decr="";
    for(int i=0; i<msg.length(); i++){
        if(isupper(msg[i]) && isupper(key[i%key.length()])){
            decr+=char((int(msg[i])-int(key[i%key.length()])-65)%26+26+65);
        }
        if(islower(msg[i]) && islower(key[i%key.length()])){
            decr+=char((int(msg[i])-int(key[i%key.length()])-97)%26+26+97);
        }
    }
    return decr;
    
}

int main(){
    string msg, key, enc, dec;
    cout<<"Enter the message:"<<endl;
    cin>>msg;
    cout<<"Enter the key:"<<endl;
    cin>>key;
    enc=v_enc(msg,key);
    dec=v_dec(enc,key);
    cout<<"Encrypted message is: "<<enc<<endl;
    cout<<"Decrypted message is: "<<dec<<endl;
    return 0;
}