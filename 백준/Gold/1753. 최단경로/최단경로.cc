#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int V, E, K;
    cin >> V >> E >> K;
    vector<vector<pair<int, int>>> edges(V+1);
    while (E--) {
        int u,v,w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    const int INF = 1e9;
    vector<int> distance(V+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> dijkstra;
    distance[K] = 0;
    dijkstra.push({0, K});

    while (!dijkstra.empty()) {
        auto [dist, curr] = dijkstra.top();
        dijkstra.pop();

        if (distance[curr] < dist) continue;

        for (auto [v, w] : edges[curr]) {
            if (distance[v] > distance[curr] + w) {
                distance[v] = distance[curr] + w;
                dijkstra.push({distance[v], v});
            }
        }
    }
    for (int i = 1; i <= V; ++i) {
        if (distance[i] == INF) {
            cout << "INF";
        } else cout << distance[i];
        cout << '\n';
    }
    

    return 0;
}