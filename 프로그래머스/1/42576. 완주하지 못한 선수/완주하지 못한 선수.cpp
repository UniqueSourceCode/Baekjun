#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hash;
    for (auto& name : completion) {
        hash[name]--;
    }
    for (auto& name : participant) {
        hash[name]++;
        if (hash[name] > 0) {
            answer = name;
            break;
        }
    }
    return answer;
}