#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), [](auto& a, auto& b) {
       return a > b; 
    });
    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] >= i+1) {
            answer = i+1;
        } else break;
    }
    
    return answer;
}