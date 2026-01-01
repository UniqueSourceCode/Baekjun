#include <iostream>
using namespace std;

int main() {    
    int x, y, z;
    bool isValid;
    cin >> x >> y >> z;

    isValid = (y < z);

    if (isValid) {
        cout << x/(z-y) + 1;
    } else {
        cout << -1;
    }
    return 0;
}