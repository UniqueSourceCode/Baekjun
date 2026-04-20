#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (char& s : number) {
        while (k > 0 && !answer.empty() && answer.back() < s) {
            answer.pop_back();
            k--;
        }
        answer.push_back(s);
    }
    
    while (k--) answer.pop_back();
    
    return answer;
}