#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int modular = 1e9 + 7;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (auto puddle : puddles) {
        dp[puddle[0]][puddle[1]] = -1;
    }
    dp[0][1] = 1;
    for (int i = 1; i< m+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%modular;
            }
        }
    }
    answer = dp[m][n];
    return answer;
}