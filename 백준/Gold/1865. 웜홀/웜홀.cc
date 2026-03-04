#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int TC;
    int INF = 1e9;
    cin >> TC;
    while (TC--) {
        int N, M, W;
        cin >> N >> M >> W;
        vector<vector<pair<int, int>>> edges(N+1);
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }

        for (int i = 0; i < W; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[u].push_back({v, -w});
        }

        vector<int> dist(N+1, 0);


        //Connect all nodes to a dummy node
        for (int i = 1; i < N+1; ++i) {
            edges[0].push_back({i, 0});
        }

        for (int j = 0; j < N-1; ++j) {
            for (int k = 0; k < N+1; ++k) {
                for (auto [v, w] : edges[k]) {
                    if (dist[k] + w < dist[v]) {
                        dist[v] = dist[k] + w;
                    }
                }
            }
        } 

        bool negative_cycle = false;
        for (int j = 0; j < N+1; ++j) {
            for (auto [v, w] : edges[j]) {
                if (dist[j] + w < dist[v]) {
                    negative_cycle = true;
                }
            }
        }
        
        if (negative_cycle) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}