#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

bool queen_space[15][15] = {false};

bool IsSpaceAvailable(int r, int c, int N) {
    for (int i = 0; i < r; ++i) {
        if (queen_space[i][c]) return false;
        if (r-i-1 >= 0 && c-i-1 >= 0 && queen_space[r-i-1][c-i-1]) return false;
        if (r-i-1 >= 0 && c+i+1 < N && queen_space[r-i-1][c+i+1]) return false;
    }
    return true;
}

void NQueens (int N, int row, int& count) {
    if (row >= N) {
        count++;
        return;
    }
    for (int c = 0; c < N; ++c) {
        if (!IsSpaceAvailable(row, c, N)) continue;
        queen_space[row][c] = true;
        NQueens(N, row + 1, count);
        queen_space[row][c] = false;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    int count = 0;
    NQueens(N, 0, count);
    cout << count;
    return 0;
}