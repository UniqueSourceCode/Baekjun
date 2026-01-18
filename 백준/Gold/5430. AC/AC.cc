#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string p;
        cin >> p;

        int n;
        cin >> n;
        vector<int> arr(n);
        
        string x;
        cin >> x;
        replace(x.begin(), x.end(), ',', ' ');
        replace(x.begin(), x.end(), '[', ' ');
        replace(x.begin(), x.end(), ']', ' ');
        istringstream ss(x);

        for (int i = 0; i < n; ++i) {
            int y;
            ss >> y;
            arr[i] = y;
        }

        int len = p.length();
        bool error = false;
        bool direction = true;
        int pointer = 0;
        for (int i = 0; i < len; ++i) {
            if (p[i] == 'R') {
                direction ? pointer += n-1 : pointer -= n-1;
                direction = !direction;
            }
            if (p[i] == 'D') {
                if (n == 0) {
                    error = true;
                    break;
                }
                direction ? pointer += 1 : pointer -= 1;
                n--;
            }
        }

        if (error) {
            cout << "error" << '\n';
            continue;
        }
        string ans = "[";
        while (n--) {
            ans += to_string(arr[pointer]) + ',';
            direction ? pointer += 1 : pointer -= 1;
        }
        if (ans != "[") ans.pop_back();
        ans += ']';
        cout << ans << '\n';
    }
    return 0;
}