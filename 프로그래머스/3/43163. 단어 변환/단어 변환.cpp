#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int target_index;

    words.insert(words.begin(), begin);
    auto it = find(words.begin(), words.end(), target);
    if (it != words.end()) {
        target_index = it - words.begin();
    } else return 0;

    int n = words.size();
    int word_len = words[0].size();
    vector<bool> visited(n, false);
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int count = 0;
            for (int k = 0; k < word_len; ++k) {
                if (words[i][k] != words[j][k]) count++;
            }
            if (count == 1) adj[i].push_back(j);
        }
    }

    queue<int> BFS;
    BFS.push(0);
    visited[0] = true;

    int count = 0;

    while (!BFS.empty() && !visited[target_index]) {
        count++;
        int size = BFS.size();
        while (size--) {
            int curr = BFS.front(); BFS.pop();
            for (auto& next : adj[curr]) {
                if (visited[next]) continue;
                BFS.push(next);
                visited[next] = true;
            }
        }
    }
    (visited[target_index]) ? answer = count : answer = 0;
    return answer;
}