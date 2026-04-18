#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int n : scoville) pq.push(n);
    while (!pq.empty() && pq.top() < K) {
        ++answer;
        int x = pq.top(); pq.pop();
        if (pq.empty()) return -1;
        int y = pq.top(); pq.pop();
        pq.push(x + y*2);
    }
    return answer;
}