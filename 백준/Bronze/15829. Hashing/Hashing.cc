#include <iostream>
#include <string>
using namespace std;

int main() {
    int L;
    int r = 31;
    int M = 1234567891;
    cin >> L;
    string s;
    cin >> s;
    long H = 0;
    for (int i = 0; i < L; ++i) {
        long curr = s[i] - 'a' + 1;
        for (int j = 0; j < i; ++j) {
            curr = (curr*r)%M;
        }
        H = (H + curr)%M;
    }
    cout << H;
    return 0;
}