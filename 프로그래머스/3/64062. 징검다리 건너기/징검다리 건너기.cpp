#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    deque<int> deq;
    for (int i = 0; i < k; ++i) {
        while (!deq.empty() && stones[i] > deq.back()) {
            deq.pop_back();
        }
        deq.push_back(stones[i]);
    }
    answer = deq.front();
    
    
    for (int l = 0; l < stones.size(); ++l) {
        if (l+k > stones.size()-1) break;
        if (stones[l] == deq.front()) deq.pop_front();
        while (!deq.empty() && stones[l+k] > deq.back()) {
            deq.pop_back();
        }
        deq.push_back(stones[l+k]);
        
        if (deq.front() < answer) answer = deq.front();
        
    }
    return answer;
}