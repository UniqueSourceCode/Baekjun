#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        string s;
        getline(cin, s);
        if (s == ".") break;
        
        int len = s.length();
        bool valid = true;
        stack<char> parentheses;

        for (int i = 0; i < len-1; ++i) {
            if (s[i] == '[' || s[i] == ']' || s[i] == '(' || s[i] == ')') {
                if (parentheses.empty()) {
                    parentheses.push(s[i]);
                    continue;
                }
                if (s[i] == '(' || s[i] == '[') parentheses.push(s[i]);
                if (s[i] == ')') {
                    if (parentheses.top() == '(') parentheses.pop();
                    else {
                        valid = false;
                        break;
                    }
                }
                if (s[i] == ']') {
                    if (parentheses.top() == '[') parentheses.pop();
                    else {
                        valid = false;
                        break;
                    }
                }
            }
        }

        if (s[len-1] != '.' || !parentheses.empty()) valid = false;

        if (valid) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;
}