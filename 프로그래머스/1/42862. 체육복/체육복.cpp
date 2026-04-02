#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> total(n+1, 1);
    for (auto& p : lost) total[p]--;
    for (auto& p : reserve) total[p]++;
    for (int i = 1; i < n; ++i) {
        if (total[i] > 1 && total[i+1] == 0) {
            total[i]--;
            total[i+1]++;
        }
        if (total[i+1] > 1 && total[i] == 0) {
            total[i+1]--;
            total[i]++;
        }
        if (total[i] > 0) answer++;
    }
    if (total[n] > 0) answer++;
    return answer;
}