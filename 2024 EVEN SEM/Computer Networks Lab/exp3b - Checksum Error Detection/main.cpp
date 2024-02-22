#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int calculateChecksum(const string& data) {
    int checksum = 0;
    for (char c : data) {
        checksum += (int)c;
    }
    return checksum;
}

bool verifyChecksum(const string& data, int checksum) {
    int calculatedChecksum = calculateChecksum(data);
    return calculatedChecksum == checksum;
}

int main() {
    string data;
    int checksum;
    int err = 0;

    cout << "Enter data: ";
    getline(cin, data);
    checksum = calculateChecksum(data);
    cout << "Checksum: " << checksum << endl;
    
    cout << "Simulating transmission..." << endl;
    if (err == 1) {
        srand(time(0));
        int bitToFlip = rand() % data.size();
        data[bitToFlip] ^= 1;
        cout << "Error introduced: Flipping bit at position " << bitToFlip << endl;
    }
    
    if (verifyChecksum(data, checksum)) {
        cout << "Checksum verified. Data received without error." << endl;
    } else {
        cout << "Checksum verification failed. Data corrupted during transmission." << endl;
    }

    return 0;
}
