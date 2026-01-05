#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int maximum = 0;
    int arr[100] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int num = arr[i] + arr[j] + arr[k];
                if ((num > maximum) && (num <= m)) maximum = num;
            }
        }
    }
    cout << maximum;
    return 0;
}