
#include <bits/stdc++.h>
using namespace std;

// 22. Generate Parentheses
class GenerateParentheses {
public:
    vector<string> res;
    void backtrack(string curr, int open, int close, int n) {
        if (curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if (open < n) backtrack(curr + "(", open + 1, close, n);
        if (close < open) backtrack(curr + ")", open, close + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return res;
    }
};

// 39. Combination Sum
class CombinationSum {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                path.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i, path);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backtrack(candidates, target, 0, path);
        return res;
    }
};

// 17. Letter Combinations of a Phone Number
class LetterCombinations {
public:
    vector<string> res;
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(string& digits, int index, string curr) {
        if (index == digits.size()) {
            if (!curr.empty()) res.push_back(curr);
            return;
        }
        for (char c : mapping[digits[index] - '0']) {
            backtrack(digits, index + 1, curr + c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtrack(digits, 0, "");
        return res;
    }
};

// Driver Code Example
int main() {
    // Generate Parentheses
    GenerateParentheses gp;
    vector<string> paren = gp.generateParenthesis(3);
    cout << "Generate Parentheses:\n";
    for (auto &s : paren) cout << s << " ";
    cout << "\n\n";

    // Combination Sum
    CombinationSum cs;
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> comb = cs.combinationSum(candidates, 7);
    cout << "Combination Sum:\n";
    for (auto &vec : comb) {
        cout << "[ ";
        for (int num : vec) cout << num << " ";
        cout << "] ";
    }
    cout << "\n\n";

    // Letter Combinations
    LetterCombinations lc;
    vector<string> letters = lc.letterCombinations("23");
    cout << "Letter Combinations:\n";
    for (auto &s : letters) cout << s << " ";
    cout << "\n";

    return 0;
}
