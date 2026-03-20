#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        //choose 1st, 2nd or none;
        int dp[3] = {0};
        vector<int> first_row(n);
        vector<int> second_row(n);
        for (int i = 0; i < n; ++i) {
            cin >> first_row[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> second_row[i];
        }
        
        for (int i = 0; i < n; ++i) {
            int first, second, third;
            first = max(dp[1] + first_row[i], dp[2] + first_row[i]);
            second = max(dp[0] + second_row[i], dp[2] + second_row[i]);
            third = max(dp[0], dp[1]);
            dp[0] = first;
            dp[1] = second;
            dp[2] = third;
        }
        cout << max(max(dp[0], dp[1]), dp[2]) << '\n';
    }
    return 0;
}