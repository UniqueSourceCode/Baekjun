#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int grid[20][20];
int N;
int level = 2;
int directions[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int fish_distance(int &shark_x, int &shark_y) {
    int visited[20][20] = {false};
    queue<pair<int, int>> BFS;
    visited[shark_x][shark_y] = true;
    BFS.push({shark_x, shark_y});
    int prev_shark_x = shark_x;
    int prev_shark_y = shark_y;
    int found = false;
    int distance = 0;
    while (!BFS.empty()) {
        if (found) break;
        ++distance;
        int count = BFS.size();
        while (count--) {
            auto [x, y] = BFS.front();
            BFS.pop();

            for (int i = 0; i < 4; ++i) {
                int new_x = x + directions[i][0];
                int new_y = y + directions[i][1];
                if (visited[new_x][new_y]) continue;
                if (new_x < 0 || new_x > N-1 || new_y < 0 || new_y > N-1) continue;
                visited[new_x][new_y] = true;
                if (grid[new_x][new_y] > level) continue;
                if (grid[new_x][new_y] > 0 && grid[new_x][new_y] < level) found = true;
                BFS.push({new_x, new_y});
            }
        }
    }
    if (found) {
        shark_x = N;
        shark_y = N;
        while (!BFS.empty()) {
            auto [x, y] = BFS.front();
            BFS.pop();
            if (grid[x][y] == 0 || grid[x][y] >= level) continue;
            if (x < shark_x) {
                shark_x = x;
                shark_y = y;
            } else if (y < shark_y && x == shark_x) {
                shark_x = x;
                shark_y = y;
            }
        }
        return distance;
    } else return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int experience = 0;
    int time = 0;
    int x, y;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;
            grid[i][j] = num;
            if (num == 9) {
                x = i;
                y = j;
                grid[i][j] = 0;
                continue;
            }
        }
    }
    while (true) {
        if (experience == level) {
            level++;
            experience = 0;
        }
        int distance = fish_distance(x, y);
        if (distance == 0) break;

        time += distance;
        experience++;
        grid[x][y] = 0;
    }
    
    cout << time;

    return 0;
}