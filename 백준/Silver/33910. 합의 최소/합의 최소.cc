#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long sum = 0;
    int n;
    int min = 0, minCount = 1;
    cin >> n;
    vector<int> nums(n);
    //reverse input for easier solving later
    for (int i = n-1; i >= 0; --i) {
        cin >> nums[i];
    }
    min = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] >= min) {
            minCount++;
        } else {
            sum += 1LL * minCount*min;
            minCount = 1;
            min = nums[i];
        }
    }
    sum += 1LL * minCount*min;
    cout << sum;
    return 0;
}