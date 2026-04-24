#include <string>
#include <vector>

using namespace std;

vector<int> solution(int target) {
    vector<int> answer;
    int size = (target > 60) ? target : 60;
    vector<vector<int>> dp(size+1, vector<int>(2));
    for (auto& v : dp) {
        v[0] = 1e7;
        v[1] = 0;
    }
    for (int i = 1; i <= 20; ++i) {
        dp[i*2][0] = 1;
        dp[i*2][1] = 0;
        dp[i*3][0] = 1;
        dp[i*3][1] = 0;
    }
    for (int i = 1; i <= 20; ++i) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }
    dp[50][0] = 1;
    dp[50][1] = 1;
    for (int i = 1; i <= target; ++i) {
        int minx = dp[i][0];
        int maxy = dp[i][1];
        for (int j = 1; j < 61; ++j) {
            if (i-j <= 0) break;
            if (dp[i-j][0] + dp[j][0] < minx) {
                minx = dp[i-j][0] + dp[j][0];
                maxy = dp[i-j][1] + dp[j][1];
            } else if (dp[i-j][0] + dp[j][0] == minx) {
                if (dp[i-j][1] + dp[j][1] > maxy) {
                    maxy = dp[i-j][1] + dp[j][1];
                }
            }
        }
        dp[i][0] = minx;
        dp[i][1] = maxy;
    }
    answer.push_back(dp[target][0]);
    answer.push_back(dp[target][1]);
    return answer;
}