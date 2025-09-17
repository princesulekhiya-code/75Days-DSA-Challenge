#include <bits/stdc++.h>
using namespace std;

/*-------------------------------------------------
1️⃣ Problem 3: Longest Substring Without Repeating Characters
Approach: Sliding Window + HashMap
-------------------------------------------------*/
class SolutionLongestSubstring {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, -1);
        int left = 0, maxLen = 0;
        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] >= left) {
                left = freq[s[right]] + 1;
            }
            freq[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

/*-------------------------------------------------
2️⃣ Problem 438: Find All Anagrams in a String
Approach: Fixed Sliding Window + Frequency Count
-------------------------------------------------*/
class SolutionFindAnagrams {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        vector<int> ans;
        vector<int> cntS(26, 0), cntP(26, 0);

        for (char c : p) cntP[c - 'a']++;

        for (int i = 0; i < s.size(); i++) {
            cntS[s[i] - 'a']++;
            if (i >= p.size()) {
                cntS[s[i - p.size()] - 'a']--;
            }
            if (cntS == cntP) {
                ans.push_back(i - p.size() + 1);
            }
        }
        return ans;
    }
};

/*-------------------------------------------------
3️⃣ Problem 424: Longest Repeating Character Replacement
Approach: Sliding Window + Max Frequency Count
-------------------------------------------------*/
class SolutionCharacterReplacement {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, maxCount = 0, maxLen = 0;
        for (int right = 0; right < s.size(); right++) {
            maxCount = max(maxCount, ++count[s[right] - 'A']);
            while ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

/*-------------------------------------------------
Main Function for Testing
-------------------------------------------------*/
int main() {
    // Problem 3: Longest Substring Without Repeating Characters
    SolutionLongestSubstring sol1;
    cout << "Longest Substring Without Repeating Characters (\"abcabcbb\"): "
         << sol1.lengthOfLongestSubstring("abcabcbb") << endl;

    // Problem 438: Find All Anagrams in a String
    SolutionFindAnagrams sol2;
    vector<int> anagrams = sol2.findAnagrams("cbaebabacd", "abc");
    cout << "Find All Anagrams in \"cbaebabacd\" for \"abc\": ";
    for (int idx : anagrams) cout << idx << " ";
    cout << endl;

    // Problem 424: Longest Repeating Character Replacement
    SolutionCharacterReplacement sol3;
    cout << "Longest Repeating Character Replacement (\"AABABBA\", k=1): "
         << sol3.characterReplacement("AABABBA", 1) << endl;

    return 0;
}
day11.cpp
