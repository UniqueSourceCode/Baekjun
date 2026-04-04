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
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> edges(N+1);
    
    for (int i = 0; i < N-1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});;
    }

    priority_queue<pair<int, int>> pq;
    vector<int> dist(N+1, 1e9);
    dist[1] = 0;
    pq.push({dist[1], 1});

    int farthest_node = 1;
    int farthest_distance = 0;
    
    while (!pq.empty()) {
        auto [curr_distance, curr_node] = pq.top();
        pq.pop();
        if (curr_distance > dist[curr_node]) continue;
        for (auto& [v, w] : edges[curr_node]) {
            if (dist[v] > dist[curr_node] + w) {
                dist[v] = dist[curr_node] + w;
                if (dist[v] > farthest_distance) {
                    farthest_distance = dist[v];
                    farthest_node = v;
                }
                pq.push({dist[v], v});
            }
        }
    }

    fill(dist.begin(), dist.end(), 1e9);

    dist[farthest_node] = 0;
    pq.push({dist[farthest_node], farthest_node});

    int diameter = 0;
    
    while (!pq.empty()) {
        auto [curr_distance, curr_node] = pq.top();
        pq.pop();
        if (curr_distance > dist[curr_node]) continue;
        for (auto& [v, w] : edges[curr_node]) {
            if (dist[v] > dist[curr_node] + w) {
                dist[v] = dist[curr_node] + w;
                if (dist[v] > diameter) {
                    diameter = dist[v];
                }
                pq.push({dist[v], v});
            }
        }
    }
    cout << diameter;

    
    

    return 0;
}