#include <bits/stdc++.h>
using namespace std;

string bitwiseXOR(string operand1, string operand2)
{
    string result = "";
    int length = operand2.length();
    for (int i = 1; i < length; i++) { // Start loop from 1
        if (operand1[i] == operand2[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}

string modulo2Division(string dividend, string divisor)
{
    int divisorLength = divisor.length();
    string temp = dividend.substr(0, divisorLength);
    int length = dividend.length();

    while (divisorLength < length) {
        if (temp[0] == '1')
            temp = bitwiseXOR(divisor, temp) + dividend[divisorLength];
        else
            temp = bitwiseXOR(std::string(divisorLength, '0'), temp) + dividend[divisorLength];
        divisorLength += 1;
    }

    if (temp[0] == '1')
        temp = bitwiseXOR(divisor, temp);
    else
        temp = bitwiseXOR(std::string(divisorLength, '0'), temp);

    return temp;
}

void encodeData(string data, string key)
{
    int keyLength = key.length();
    string appendedData = (data + std::string(keyLength - 1, '0'));
    string remainder = modulo2Division(appendedData, key);
    string codeword = data + remainder;
    cout << "Remainder : " << remainder << "\n";
    cout << "Encoded Data (Data + Remainder) :" << codeword << "\n";
}

string decodeData(string receivedData, string key)
{
    string currentXOR = modulo2Division(receivedData.substr(0, key.size()), key);
    int current = key.size();
    while (current != receivedData.size()) {
        if (currentXOR.size() != key.size()) {
            currentXOR.push_back(receivedData[current++]);
        }
        else {
            currentXOR = modulo2Division(currentXOR, key);
        }
    }
    if (currentXOR.size() == key.size()) {
        currentXOR = modulo2Division(currentXOR, key);
    }
    return currentXOR;
}

int main()
{
    string data = "100100";
    string key = "1101";
    
    cout << "Sender side..." << endl;
    encodeData(data, key);

    cout << "\nReceiver side..." << endl;
    string receivedData = data + modulo2Division(data + std::string(key.size() - 1, '0'), key);
    string decodedData = decodeData(receivedData, key);
    
    if (decodedData.find('1') != string::npos) {
        cout << "There is some error in data" << endl;
    }
    else {
        cout << "Correct message received: " << decodedData << endl;
    }

    return 0;
}
