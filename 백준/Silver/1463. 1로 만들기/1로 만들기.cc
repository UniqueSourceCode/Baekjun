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
            min_val = 1 + min(min(arr[i/3], arr[i/2]), arr[i-1]);
        } else if ((i+1) % 3 == 0) {
            min_val = 1 + min(arr[i/3], arr[i-1]);
        } else if ((i+1) % 2 == 0) {
            min_val = 1 + min(arr[i/2], arr[i-1]);
        } else {
            min_val = arr[i-1] + 1;
        }
        arr[i] = min_val;
    }
    cout << arr[n-1];
    return 0;
}