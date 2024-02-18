#include <iostream>

using namespace std;

int main() {
    int num, mod, z, x, a = 0;

    cout << "Enter a number, with a maximum of 3 digits." << endl;
    cin >> num;

    if (num >= 0 && num <= 999) {
        x = num;
        while (x != 0) {
            z = x % 10;
            a = a * 10 + z;
            x /= 10;
        }

        while (a != 0) {
            mod = a % 10;
            switch (mod) {
                case 0:
                    cout << "ZERO ";
                    break;
                case 1:
                    cout << "ONE ";
                    break;
                case 2:
                    cout << "TWO ";
                    break;
                case 3:
                    cout << "THREE ";
                    break;
                case 4:
                    cout << "FOUR ";
                    break;
                case 5:
                    cout << "FIVE ";
                    break;
                case 6:
                    cout << "SIX ";
                    break;
                case 7:
                    cout << "SEVEN ";
                    break;
                case 8:
                    cout << "EIGHT ";
                    break;
                case 9:
                    cout << "NINE ";
                    break;
            };

            a /= 10;
        }
    } else {
        cout << "Error! The entered number is out of range!";
    }

    return 0;
}
