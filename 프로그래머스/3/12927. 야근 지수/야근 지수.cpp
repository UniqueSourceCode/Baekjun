#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for (auto& x : works) pq.push(x);
    while (!pq.empty() && n != 0) {
        int x = pq.top(); pq.pop();
        if (x == 0) continue;
        pq.push(x-1);
        n--;
    }
    while (!pq.empty()) {
        answer += (long long)pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}