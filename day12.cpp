#include <bits/stdc++.h>
using namespace std;

// 49. Group Anagrams
class Solution49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto &p : mp) result.push_back(p.second);
        return result;
    }
};

// 387. First Unique Character in a String
class Solution387 {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

// 242. Valid Anagram
class Solution242 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        for (char c : t) {
            if (--freq[c - 'a'] < 0) return false;
        }
        return true;
    }
};

int main() {
    // Example runs (for local testing only)

    // Group Anagrams
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution49 sol49;
    auto grouped = sol49.groupAnagrams(strs);
    cout << "Group Anagrams: [";
    for (int i = 0; i < grouped.size(); i++) {
        cout << "[";
        for (int j = 0; j < grouped[i].size(); j++) {
            cout << "\"" << grouped[i][j] << "\"";
            if (j < grouped[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < grouped.size() - 1) cout << ",";
    }
    cout << "]\n";

    // First Unique Character
    Solution387 sol387;
    cout << "First Unique Character (leetcode): " << sol387.firstUniqChar("leetcode") << "\n";

    // Valid Anagram
    Solution242 sol242;
    cout << "Valid Anagram (anagram, nagaram): " 
         << (sol242.isAnagram("anagram","nagaram") ? "true" : "false") << "\n";

    return 0;
}
