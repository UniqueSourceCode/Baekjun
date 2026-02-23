#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int dist[101][101];
    int graph[101][101];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            (i == j) ?  graph[i][j] = 0 : graph[i][j] = INF;
            dist[i][j] = INF;
        }
    }

    for (int i = 1; i <=m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (graph[a][b] > c) graph[a][b] = c;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; ++i) {
        pq.push({0, i});
        
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[i][node]) continue;

            for (int j = 1; j <= n; ++j) {
                if (dist[i][j] > graph[node][j] + d) {
                    dist[i][j] = graph[node][j] + d;
                    pq.push({dist[i][j], j});
                }
            }
        }
    }
    for (int i = 1; i <=n; ++i) {
        for (int j =1; j <=n; ++j) {
            if (dist[i][j] == INF) {
                cout << 0 << ' ';
            } else {
            cout << dist[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}