#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int current = n/2;
    int digits = 0;
    bool found = false;
    while (true) {
        int M = current;
        while (M > 0) {
            digits += M%10;
            M = M/10;
        }
        M = current;
        M += digits;
        digits = 0;
        current++;
        if (M == n) {
            found = true;
            break;
        }
        if (current >= n) {
            break;
        }
    }
    (found) ? cout << current-1 : cout << 0;
    return 0;
}