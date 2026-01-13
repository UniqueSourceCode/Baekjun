#include <iostream>
using namespace std;

int main() {
    int arr[8] = {};
    for (int i = 0; i < 8; ++i) {
        int N;
        cin >> N;
        arr[i] = N;
    }
    bool ascending = true;
    bool descending = true;
    for (int i = 0; i < 7; ++i) {
        if (arr[i] > arr[i+1]) ascending = false;
        if (arr[i] < arr[i+1]) descending = false;
    }
    if (ascending) cout << "ascending";
    else if (descending) cout << "descending";
    else cout << "mixed";
}