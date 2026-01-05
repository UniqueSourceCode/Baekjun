#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    int age = 0;
    string name = "";
};

int main() {
    int n;
    cin >> n;
    vector<Person> arr(n);
    for (int i = 0; i<n; ++i) {
        int age;
        string name;
        cin >> age >> name;
        arr[i] = Person{age, name};
    }
    stable_sort(arr.begin(), arr.end(), [](const Person p, const Person q) {
        return p.age < q.age;
    });
    for (const auto& p : arr) {
        cout << p.age << " " << p.name << "\n";
    }
    return 0;
}