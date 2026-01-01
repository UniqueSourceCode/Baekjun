#include <iostream>
using namespace std;

int main() {
    //if NxM, for easier calculation, N>M.
    //think of 10x6 or somemthing, we need to first cut 5 times.
    //then for each pieceof 10x1, we cut 10-1 times.
    //so that is... M-1 + N*(M-1) = NM-1 cuts in total.
    int N, M;
    cin >> N >> M;
    if (N < M) {
        swap(N, M);
    }
    cout << N * M - 1 << endl;
    return 0;
}   