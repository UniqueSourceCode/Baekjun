#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long n;
    cin >> n;
    long arr[10000] = {0};
    for (long i = 0; i<n; ++i) {
        short a;
        cin >> a;
        arr[a-1]++;
    }
    for (int i = 0; i<10000; ++i) {
        if (arr[i]) {
            while (arr[i]--) {
                cout << i+1 << "\n";
            }
        }
    }
    return 0;
}