#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    while (cin >> n) {
        if (n == "0") break;
        int length = n.length();
        bool palindrome = true;
        for (int i = 0; i < length / 2; ++i) {
            if (n[i] != n[length - 1 - i]) {
                palindrome = false;
            }
        }
        cout << (palindrome ? "yes" : "no") << endl;
    }
}