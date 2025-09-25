# Day 19 – DSA Revision

### Problems Solved Today:

1️⃣ **162. Find Peak Element**  
Find any peak element in an array where a peak is greater than its neighbors.  
**Tags:** Array, Binary Search  

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
