#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> num(N);
    vector<int> dp(N,0);
    int max_partial_length = 0;
    for (int i = 0; i < N; ++i) {
        cin >> num[i];
        int prev_dp = 0;
        for (int j = 0; j < i; ++j) {
            if (num[j] < num[i] && prev_dp < dp[j]) {
                prev_dp = dp[j];
            }
        }
        dp[i] = prev_dp + 1;
        if (max_partial_length < dp[i]) max_partial_length = dp[i];
    }
    cout << max_partial_length;
    return 0;
}