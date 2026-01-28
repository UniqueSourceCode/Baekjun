#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    set<string> heard;
    vector<string> heard_and_seen;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        heard.insert(s);
        
    }
    for (int i = 0; i < M; ++i) {
        string seen;
        cin >> seen;
        if (heard.find(seen) != heard.end()) {
            heard_and_seen.push_back(seen);
        }
    }
    sort(heard_and_seen.begin(), heard_and_seen.end());
    cout << heard_and_seen.size() << '\n';
    for (const auto s : heard_and_seen) {
        cout << s << '\n';
    }
    return 0;
}