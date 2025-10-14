// 🚀 75 Days DSA Challenge – Day 38
// 📚 Stack Advanced Series – Design & Implementation
// Problems Solved:
// 1️⃣ 150. Evaluate Reverse Polish Notation
// 2️⃣ 155. Min Stack
// 3️⃣ 1381. Design a Stack With Increment Operation
// Language: C++
// Author: @princsulekhiya
// -----------------------------------------------


// =======================================================
// ✅ Problem 1: 150. Evaluate Reverse Polish Notation
// =======================================================
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (t == "+") st.push(a + b);
                else if (t == "-") st.push(a - b);
                else if (t == "*") st.push(a * b);
                else st.push(a / b);
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};

int main() {
    Solution s;
    vector<string> tokens = {"2","1","+","3","*"};
    cout << "Result of RPN: " << s.evalRPN(tokens) << endl;
    return 0;
}


// =======================================================
// ✅ Problem 2: 155. Min Stack
// =======================================================

class MinStack {
public:
    stack<int> s, minS;

    MinStack() {}

    void push(int val) {
        s.push(val);
        if (minS.empty() || val <= minS.top())
            minS.push(val);
    }

    void pop() {
        if (s.top() == minS.top())
            minS.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};


// =======================================================
// ✅ Problem 3: 1381. Design a Stack With Increment Operation
// =======================================================

class CustomStack {
public:
    int maxSize;
    vector<int> stack;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (stack.size() < maxSize)
            stack.push_back(x);
    }

    int pop() {
        if (stack.empty())
            return -1;
        int top = stack.back();
        stack.pop_back();
        return top;
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, (int)stack.size()); i++)
            stack[i] += val;
    }
};


// =======================================================
// 🔚 End of Day 38 Codes
// =======================================================
