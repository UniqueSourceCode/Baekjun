#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int j = 0;
    int count = 0;
    vector<bool> A(N, true);
    cout << "<";
    for (int i = 0; i < N; 0) {
        if (A[j]) {
            count++;
            if (count == K) {
                cout << j + 1;
                A[j] = false;
                count = 0;
                i++;
                if (i != N) {
                    cout << ", ";
                }
            }
        }
        j = (j + 1) % N;
    }
    cout << ">" << endl;
}