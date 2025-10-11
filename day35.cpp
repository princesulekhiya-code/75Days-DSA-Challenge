// 🚀 75 Days DSA Challenge – Day 35
// Topics: Stack | Monotonic Stack | Array | Data Structure Optimization

// ✅ 1️⃣ 84. Largest Rectangle in Histogram
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};

// ✅ 2️⃣ 901. Online Stock Span
class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {}
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

// ✅ 3️⃣ 739. Daily Temperatures
class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    // Example runs

    // Problem 1
    Solution1 s1;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << s1.largestRectangleArea(heights) << endl;

    // Problem 2
    StockSpanner spanner;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    cout << "Stock Spans: ";
    for (int price : prices) cout << spanner.next(price) << " ";
    cout << endl;

    // Problem 3
    Solution2 s2;
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = s2.dailyTemperatures(temps);
    cout << "Daily Temperatures: ";
    for (int r : res) cout << r << " ";
    cout << endl;

    return 0;
}
