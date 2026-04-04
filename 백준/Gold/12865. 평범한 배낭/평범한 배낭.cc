#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; ++i) {
        int w, v;
        cin >> w >> v;
        items[i] = {w, v};
    }

    //maximum value at max weight index
    vector<int> dp(K+1,0);
    

    for (int i = 0; i < N; ++i) {
        //go backwards to avoid counting multiple items
        for (int j = K; j >= items[i].first; --j) {
            //compare between
            //A : if we took the weight, maximum value at the lost weight + value of curr object
            //B : if we didn't, no change
            dp[j] = max(dp[j], dp[j - items[i].first] + items[i].second);
        }
    }
    
    cout << dp[K];

    return 0;
}