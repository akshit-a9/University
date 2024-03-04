#include <iostream>
#include <string>

using namespace std;

string decToOct(double dec) {
    int intP = dec;
    double frac = dec - intP;

    string oct = "";
    while (intP > 0) {
        int rem = intP % 8;
        oct = to_string(rem) + oct;
        intP /= 8;
    }

    string octFrac = "";
    const int maxPrec = 10;
    for (int i = 0; i < maxPrec; ++i) {
        frac *= 8;
        int digit = frac;
        octFrac += to_string(digit);
        frac -= digit;
    }

    return oct + "." + octFrac;
}

int main() {
    double dec;
    cin >> dec;

    string octal = decToOct(dec);
    cout << octal;
    return 0;
}
