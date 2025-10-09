// 🚀 75 Days DSA Challenge – Day 33
// Topic: Stack & Queue Design (Implementation Concepts)
// Problems Covered:
// 1️⃣ 232. Implement Queue using Stacks
// 2️⃣ 225. Implement Stack using Queues
// 3️⃣ 1472. Design Browser History

#include <bits/stdc++.h>
using namespace std;

/* -------------------------------------------------------------------------- */
/* 1️⃣ Problem: 232. Implement Queue using Stacks */
/* -------------------------------------------------------------------------- */
class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/* -------------------------------------------------------------------------- */
/* 2️⃣ Problem: 225. Implement Stack using Queues */
/* -------------------------------------------------------------------------- */
class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

/* -------------------------------------------------------------------------- */
/* 3️⃣ Problem: 1472. Design Browser History */
/* -------------------------------------------------------------------------- */
class BrowserHistory {
    vector<string> history;
    int curr;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
    }

    void visit(string url) {
        history.resize(curr + 1);
        history.push_back(url);
        curr++;
    }

    string back(int steps) {
        curr = max(0, curr - steps);
        return history[curr];
    }

    string forward(int steps) {
        curr = min((int)history.size() - 1, curr + steps);
        return history[curr];
    }
};

/* -------------------------------------------------------------------------- */
/* 💡 Example Usage (You can remove this before submitting on LeetCode) */
/* -------------------------------------------------------------------------- */
int main() {
    // Example for MyQueue
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << "Queue front: " << q.peek() << endl; // Output: 1
    cout << "Queue pop: " << q.pop() << endl;   // Output: 1

    // Example for MyStack
    MyStack s;
    s.push(10);
    s.push(20);
    cout << "Stack top: " << s.top() << endl;   // Output: 20
    s.pop();
    cout << "Stack top after pop: " << s.top() << endl; // Output: 10

    // Example for BrowserHistory
    BrowserHistory bh("leetcode.com");
    bh.visit("google.com");
    bh.visit("facebook.com");
    bh.visit("youtube.com");
    cout << "Back: " << bh.back(1) << endl;     // facebook.com
    cout << "Back: " << bh.back(1) << endl;     // google.com
    cout << "Forward: " << bh.forward(1) << endl; // facebook.com
    bh.visit("linkedin.com");
    cout << "Back: " << bh.back(2) << endl;     // google.com

    return 0;
}
