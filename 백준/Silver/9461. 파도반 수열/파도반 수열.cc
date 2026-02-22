#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    long dp[101] = {};
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    for (int i = 5; i <= 100; ++i) {
        dp[i] = dp[i-1] + dp[i-5];
    }
    while (T--) {
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }
    return 0;
}