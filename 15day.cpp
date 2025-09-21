// 🚀 Day 15 DSA Challenge
// Problems: 35. Search Insert Position | 153. Find Minimum in Rotated Sorted Array | 852. Peak Index in a Mountain Array
// Language: C++

#include <bits/stdc++.h>
using namespace std;

/* ============================
   35. Search Insert Position
   ============================ */
class Solution35 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};

/* ==============================================
   153. Find Minimum in Rotated Sorted Array
   ============================================== */
class Solution153 {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};

/* ===========================================
   852. Peak Index in a Mountain Array
   =========================================== */
class Solution852 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

// 🔹 Main Function to Test All
int main() {
    // Test for Problem 35
    Solution35 sol35;
    vector<int> nums = {1,3,5,6};
    int target = 5;
    cout << "Search Insert Position: " << sol35.searchInsert(nums, target) << endl;

    // Test for Problem 153
    Solution153 sol153;
    vector<int> nums2 = {4,5,6,7,0,1,2};
    cout << "Minimum in Rotated Sorted Array: " << sol153.findMin(nums2) << endl;

    // Test for Problem 852
    Solution852 sol852;
    vector<int> arr = {0,10,5,2};
    cout << "Peak Index in Mountain Array: " << sol852.peakIndexInMountainArray(arr) << endl;

    return 0;
}
