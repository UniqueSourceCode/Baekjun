#include <iostream>
#include <stack>
using namespace std;

struct Node {
    Node* next = nullptr;
    int path = 0;

    Node(Node* x, int y) : next(x), path(y) {}
};

int main() {
    Node* path[101] = {};
    bool visited[101] = {false};
    int computers, paths;
    cin >> computers >> paths;
    for (int i = 0; i < paths; ++i) {
        int a, b;
        cin >> a >> b;
        Node* curr = path[a];
        if (!curr) {
            path[a] = new Node(nullptr, b);
        } else {
            while (curr->next) curr = curr->next;
            curr->next = new Node(nullptr, b);
        }
        curr = path[b];
        if (!curr) {
            path[b] = new Node(nullptr, a);
        } else {
            while (curr->next) curr = curr->next;
            curr->next = new Node(nullptr, a);
        }
    }
    stack<int> dfs;
    dfs.push(1);
    visited[1] = true;
    int count = -1;
    while (!dfs.empty()) {
        ++count;
        int n = dfs.top();
        dfs.pop();
        Node* curr = path[n];
        while (curr) {
            int m = curr->path;
            if (visited[m]) {
                curr = curr->next;
                continue;
            }
            dfs.push(m);
            visited[m] = true;
            curr = curr->next;
        }
    }
    cout << count;

    return 0;
}