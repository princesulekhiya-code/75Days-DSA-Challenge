#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
        vector<bool> inStack(26, false);
        for (int i = 0; i < s.size(); i++) 
            lastIndex[s[i] - 'a'] = i;
        
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (inStack[c - 'a']) continue;

            while (!st.empty() && c < st.top() && lastIndex[st.top() - 'a'] > i) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[c - 'a'] = true;
        }

        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "cbacdcbc";
    cout << "Result: " << sol.removeDuplicateLetters(s) << endl;
    cout << "✅ Day 49: Remove Duplicate Letters executed successfully!" << endl;
    return 0;
}
