#include <iostream>
#include <vector>
using namespace std;

vector<int> encodeHammingCode(vector<int> &data) {
    vector<int> codedData(12);
    codedData[2] = data[0];
    codedData[4] = data[1];
    codedData[5] = data[2];
    codedData[6] = data[3];
    codedData[8] = data[4];
    codedData[9] = data[5];
    codedData[10] = data[6];
    codedData[11] = data[7];

    codedData[0] = codedData[2] ^ codedData[4] ^ codedData[6] ^ codedData[8] ^ codedData[10];
    codedData[1] = codedData[2] ^ codedData[5] ^ codedData[6] ^ codedData[9] ^ codedData[10];
    codedData[3] = codedData[4] ^ codedData[5] ^ codedData[6] ^ codedData[11];
    codedData[7] = codedData[8] ^ codedData[9] ^ codedData[10] ^ codedData[11];

    return codedData;
}
int detectError(const vector<int> &codedData) {
    int p1 = codedData[0] ^ codedData[2] ^ codedData[4] ^ codedData[6] ^ codedData[8] ^ codedData[10];
    int p2 = codedData[1] ^ codedData[2] ^ codedData[5] ^ codedData[6] ^ codedData[9] ^ codedData[10];
    int p4 = codedData[3] ^ codedData[4] ^ codedData[5] ^ codedData[6] ^ codedData[11];
    int p8 = codedData[7] ^ codedData[8] ^ codedData[9] ^ codedData[10] ^ codedData[11];

    int errorPosition = p1 + (p2 << 1) + (p4 << 2) + (p8 << 3);

    return errorPosition;
}

int main() {
    vector<int> data = {1, 0, 1, 1, 1, 0, 0, 1}; 
    vector<int> codedData = encodeHammingCode(data);
    cout << "Encoded Data with Hamming Code: ";
    for (int bit : codedData) {
        cout << bit;
    }
    cout << endl;
    // Simulate an error for testing
    codedData[3] ^= 1; // Flipping a bit to simulate an error

    int errorPosition = detectError(codedData);

    if (errorPosition) {
        cout << "Error detected at position: " << errorPosition << endl;
    } else {
        cout << "No errors detected." << endl;
    }
    return 0;
}
