#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    stack<int> s1; // main data structure
    stack<int> s2; // helper

    void push(int x) {
        s1.push(x);
    }

    void pop() {
        if (s1.empty()) {
            cout << "Queue is empty. Cannot pop." << endl;
            return;
        }

        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.pop();

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front() {
        if (s1.empty()) {
            cout << "Queue is empty. Cannot get front." << endl;
            return -1;
        }

        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }

        int x = s1.top();
        s1.pop();

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        s1.push(x);

        return x;
    }

    int size() {
        return s1.size();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << q.front() << endl;

    cout << q.size() << endl;

    q.pop();
    cout << q.front() << endl;

    cout << q.empty() << endl;

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}