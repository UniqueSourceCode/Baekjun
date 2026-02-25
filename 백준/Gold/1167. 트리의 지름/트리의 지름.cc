#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//{V, E}
vector<pair<int, int>> edges[100001];
priority_queue<int> distances_from_first;
int V, first_node;

void DFS(int start, int& max_distance, bool* visited, int& curr_distance, int& farthest_node) {
    visited[start] = true;
    for (auto [V, E] : edges[start]) {
        if (visited[V]) continue;
        curr_distance += E;
        DFS(V, max_distance, visited, curr_distance, farthest_node);
        curr_distance -= E;
    }
    if (max_distance < curr_distance) {
        max_distance = curr_distance;
        farthest_node = start;
    }
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> V;
    for (int i = 0; i < V; ++i) {
        int node;
        cin >> node;
        while (true) {
            int A, B;
            cin >> A;
            if (A == -1) break;
            cin >> B;
            edges[node].push_back({A, B});
        }
    }
    bool visited[100001] = {false};
    int farthest_node = 0;
    int curr_distance = 0;
    for (int i = 1; i <= V; ++i) {
        if (edges[i].empty()) continue;
        first_node = i;
        int temp = 0;
        DFS(i, temp, visited, curr_distance, farthest_node);
        break;
    }
    curr_distance = 0;
    int maximum_distance = 0;
    fill(visited, visited + 100001, false);
    DFS(farthest_node, maximum_distance, visited, curr_distance, farthest_node);
    cout << maximum_distance;

    return 0; 
}