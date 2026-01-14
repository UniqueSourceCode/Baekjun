#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    stack<int> s;
    queue<int> q;
    bool possible = true;
    int curr = 0;
    for (int i = 1; i <= N; ++i) {
        if (!possible) break;
        int x;
        cin >> x;
        while (s.empty() || s.top() != x) {
            ++curr;
            if (curr > N) {
                possible = false;
                break;
            }
            s.push(curr);
            q.push(0);
        }
        
        if (!s.empty() && s.top() == x) {
            s.pop();
            q.push(1);
            continue;
        }
    }
    if (!possible) cout << "NO";
    else {
        while (!q.empty()) {
            if (q.front() == 1) {
                cout << '-' << '\n';
            } else {
                cout << '+' << '\n';
            }
            q.pop();
        }
    }
    return 0;
}