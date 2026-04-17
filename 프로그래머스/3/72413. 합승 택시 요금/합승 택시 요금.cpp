#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e9));
    for (int i = 1; i < n+1; ++i) {
        dist[i][i] = 0;
    }
    for (auto& fare : fares) {
        dist[fare[0]][fare[1]] = fare[2];
        dist[fare[1]][fare[0]] = fare[2];
    }
    for (int k = 1; k < n+1; ++k) {
        for (int i = 1; i < n+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
    for (int k = 1; k < n+1; ++k) {
        if (dist[k][a] == 1e9 || dist[k][b] == 1e9 || dist[s][k] == 1e9) continue;
        answer = min(answer, dist[s][k] + dist[k][a] + dist[k][b]);
    }
    return answer;
}