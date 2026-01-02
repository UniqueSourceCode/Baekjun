#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    arr[0] = 0;
    for (int i = 1; i < n; ++i) {
        int min_val = 1000000;
        if ((i+1) % 6 == 0) {
            min_val = min(min_val, arr[i/3] + 1);
            min_val = min(min_val, arr[i/2] + 1);
            min_val = min(min_val, arr[i-1] + 1);
        } else if ((i+1) % 3 == 0) {
            min_val = min(min_val, arr[i/3] + 1);
            min_val = min(min_val, arr[i-1] + 1);
        } else if ((i+1) % 2 == 0) {
            min_val = min(min_val, arr[i/2] + 1);
            min_val = min(min_val, arr[i-1] + 1);
        } else {
            min_val = arr[i-1] + 1;
        }
        arr[i] = min_val;
    }
    cout << arr[n-1];
    return 0;
}