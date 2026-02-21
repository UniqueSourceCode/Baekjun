#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    int coins[10];
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }
    int count = 0;
    for (int j = N-1; j > -1; --j) {
        if (K == 0) break;
        while (K >= coins[j]) {
            ++count;
            K -= coins[j];
        }
    }
    cout << count;
    return 0;
}