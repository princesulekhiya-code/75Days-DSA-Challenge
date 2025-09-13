# 🚀 75 Days DSA Revision – Day 6

## ✅ Problems Solved

### 1. [209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)
- Applied **Sliding Window** for O(n) efficiency.  
- **Key Learning:** Expanding & shrinking window to achieve minimal subarray length.  

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0, ans = INT_MAX;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```

---

### 2. [845. Longest Mountain in Array](https://leetcode.com/problems/longest-mountain-in-array/)
- Identified peaks and expanded left/right to capture mountain size.  
- **Key Learning:** Achieved a **one-pass O(1) space** solution.  

```cpp
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int left = i, right = i;
                while (left > 0 && arr[left] > arr[left - 1]) left--;
                while (right < n - 1 && arr[right] > arr[right + 1]) right++;
                ans = max(ans, right - left + 1);
                i = right;
            }
        }
        return ans;
    }
};
```

---

### 3. [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)
- Performed backward merge to avoid overwriting.  
- **Key Learning:** **In-place O(m+n)** merging technique.  

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};
```

---

✨ Step by step revising important concepts and building strong problem-solving consistency 💪  
🔥 On to **Day 7!**
