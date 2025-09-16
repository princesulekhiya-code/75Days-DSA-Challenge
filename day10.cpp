#include <bits/stdc++.h>
using namespace std;

// 28. Find the Index of the First Occurrence in a String
class Solution28 {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle) return i;
        }
        return -1;
    }
};

// 26. Remove Duplicates from Sorted Array
class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int j = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

// 76. Minimum Window Substring
class Solution76 {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need, window;
        for (char c : t) need[c]++;
        int have = 0, needCount = need.size();
        int l = 0, r = 0, minLen = INT_MAX, start = 0;
        
        while (r < s.size()) {
            char c = s[r];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) have++;
            while (have == needCount) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                window[s[l]]--;
                if (need.count(s[l]) && window[s[l]] < need[s[l]]) have--;
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

// Driver main (you can test each solution here)
int main() {
    // Test for Problem 28
    Solution28 sol28;
    cout << "Problem 28: " << sol28.strStr("sadbutsad", "sad") << endl; // Output: 0

    // Test for Problem 26
    Solution26 sol26;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = sol26.removeDuplicates(nums);
    cout << "Problem 26: k = " << k << " -> ";
    for (int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << endl;

    // Test for Problem 76
    Solution76 sol76;
    cout << "Problem 76: " << sol76.minWindow("ADOBECODEBANC", "ABC") << endl; // Output: "BANC"

    return 0;
}
