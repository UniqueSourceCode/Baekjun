#include <iostream>
using namespace std;

int main() {
    int L, N, M;
    cin >> L >> N >> M;
    N = N * M * L;
    int digit[10] =  {0};
    while (N) {
        digit[N%10]++;
        N = N/10;
    }
    for (int x : digit) {
        cout << x << "\n";
    }
    return 0;
}