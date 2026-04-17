#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left  = 0;
    long long right = (long long) 1e18;
    while (left < right) {
        long long mid = left + (right - left)/2;
        long long count = 0;
        for (int time : times) {
            count += mid/time;
        }
        if (count < n) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}