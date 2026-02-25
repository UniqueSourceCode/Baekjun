#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    int i = 665;
    while (N) {
        ++i;
        int count = 0;
        int curr = i;
        while (curr != 0) {
            if (curr%10 == 6) count++;
            else count = 0;
            if (count == 3) {
                N--;
                break;
            }
            curr = curr/10;
        }
    }
    cout << i;
    return 0;
}