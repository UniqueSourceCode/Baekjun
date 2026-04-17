#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, bool> hash;
    for (string s : phone_book) {
        for (int i = 1; i < s.length(); ++i) {
            hash[s.substr(0, i)] = true;
        }
    }
    for (string s : phone_book) {
        if (hash[s] == true) {answer = false; break;}
    }
    return answer;
}