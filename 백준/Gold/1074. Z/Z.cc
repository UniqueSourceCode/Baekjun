#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    int sum = 0;
    int i = 1;
    while (r || c) {
        sum += (c % 2) * i;
        c = c/2;
        sum += (r % 2) * 2*i;
        r = r/2;
        i *= 4;
    }
    cout << sum;
    return 0;
}