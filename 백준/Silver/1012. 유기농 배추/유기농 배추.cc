#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool adjacent(const vector<int>& a, const vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]) == 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int n, m, k;
        int count = 0;
        cin >> n >> m >> k;
        vector<vector<int>> coords(k, vector<int>(2));
        vector<vector<int>> group(k, vector<int>());
        vector<int> visited(k, 0);
        for (int j = 0; j < k; ++j) {
            cin >> coords[j][0] >> coords[j][1];
        }
        for (int j = 0; j < k; ++j) {
            if (visited[j]) continue;
            visited[j] = 1;
            group[count].push_back(j);
            int adjNodes = 0;
            while (adjNodes < group[count].size()) {
                for (int l = 0; l < k; ++l) {
                    if (!visited[l] && adjacent(coords[group[count][adjNodes]], coords[l])) {
                        visited[l] = 1;
                        group[count].push_back(l);
                    }
                }
                adjNodes++;
            }
            count++;
        }
        cout << count << endl;
    }
    return 0;
}