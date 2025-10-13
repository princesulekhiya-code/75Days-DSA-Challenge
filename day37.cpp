#include <bits/stdc++.h>
using namespace std;

// 394. Decode String
class Solution1 {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> result;
        string res = "";
        int idx = 0;
        while (idx < s.size()) {
            if (isdigit(s[idx])) {
                int num = 0;
                while (isdigit(s[idx])) {
                    num = num * 10 + (s[idx] - '0');
                    idx++;
                }
                counts.push(num);
            } else if (s[idx] == '[') {
                result.push(res);
                res = "";
                idx++;
            } else if (s[idx] == ']') {
                string temp = result.top(); result.pop();
                int count = counts.top(); counts.pop();
                for (int i = 0; i < count; i++) temp += res;
                res = temp;
                idx++;
            } else {
                res += s[idx++];
            }
        }
        return res;
    }
};

// 224. Basic Calculator
class Solution2 {
public:
    int calculate(string s) {
        int result = 0, sign = 1, num = 0;
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
                i--;
            } else if (s[i] == '+') sign = 1;
            else if (s[i] == '-') sign = -1;
            else if (s[i] == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                result = stk.top() * result; stk.pop();
                result += stk.top(); stk.pop();
            }
        }
        return result;
    }
};

// 71. Simplify Path
class Solution3 {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string dir;
        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") continue;
            if (dir == "..") {
                if (!stack.empty()) stack.pop_back();
            } else stack.push_back(dir);
        }
        string res = "/";
        for (int i = 0; i < stack.size(); i++) {
            res += stack[i];
            if (i < stack.size() - 1) res += "/";
        }
        return res;
    }
};

int main() {
    Solution1 s1;
    cout << s1.decodeString("3[a2[c]]") << endl;

    Solution2 s2;
    cout << s2.calculate("(1+(4+5+2)-3)+(6+8)") << endl;

    Solution3 s3;
    cout << s3.simplifyPath("/home/user/Documents/../Pictures") << endl;

    return 0;
}
