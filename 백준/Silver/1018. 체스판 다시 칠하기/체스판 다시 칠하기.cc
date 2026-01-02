#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> board(r);
    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }
    int min = 64;
    for (int i = 0; i <= r - 8; i++) {
        for (int j = 0; j <= c - 8; j++) {
            int count = 0;
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if ((k + l) % 2 == 0 && board[i + k][j + l] == 'B') count++;
                    if ((k + l) % 2 != 0 && board[i + k][j + l] == 'W') count++;
                }
            }
            if (count > 32) count = 64 - count;
            if (min > count) {
                min = count;
            }
        }
    }
    cout << min;
    return 0;
}