#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int count = 0;
        char instructions;
        int num;
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        unordered_map<int, int> exists;
        while (N--) {
            cin >> instructions >> num;
            if (instructions == 'D') {
                if (count == 0) continue;
                count--;
                if (num == 1) {
                    while (!exists[max_heap.top()]) max_heap.pop();
                    exists[max_heap.top()]--;
                    max_heap.pop();
                }
                if (num == -1) {
                    while (!exists[min_heap.top()]) min_heap.pop();
                    exists[min_heap.top()]--;
                    min_heap.pop();
                }
            }
            if (instructions == 'I') {
                exists[num]++;
                max_heap.push(num);
                min_heap.push(num);
                count++;
            }
        }
        if (count == 0) cout << "EMPTY" << '\n';
        else {
            while (!exists[max_heap.top()]) max_heap.pop();
            cout << max_heap.top() << " ";
            while (!exists[min_heap.top()]) min_heap.pop();
            cout << min_heap.top() << '\n';
        }
        
    }
    return 0;
}