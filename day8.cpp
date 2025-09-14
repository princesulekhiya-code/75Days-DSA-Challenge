#include <bits/stdc++.h>
using namespace std;

//
// 674. Longest Continuous Increasing Subsequence
//
class LCIS {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), ans = 1, cur = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) cur++;
            else cur = 1;
            ans = max(ans, cur);
        }
        return ans;
    }
};

//
// 307. Range Sum Query - Mutable
//
class NumArray {
    vector<int> bit, arr;
    int n;
    void add(int i, int val) {
        for (++i; i <= n; i += i & -i) bit[i] += val;
    }
    int sum(int i) {
        int s = 0;
        for (++i; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++) add(i, nums[i]);
    }
    void update(int index, int val) {
        add(index, val - arr[index]);
        arr[index] = val;
    }
    int sumRange(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};

//
// 327. Count of Range Sum
//
class CountRangeSum {
    int mergeCount(vector<long>& pre, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        int mid = (left + right) / 2;
        int cnt = mergeCount(pre, left, mid, lower, upper) + mergeCount(pre, mid, right, lower, upper);
        int j = mid, k = mid, t = mid;
        vector<long> tmp(right - left);
        int r = 0;
        for (int i = left; i < mid; i++) {
            while (k < right && pre[k] - pre[i] < lower) k++;
            while (j < right && pre[j] - pre[i] <= upper) j++;
            while (t < right && pre[t] < pre[i]) tmp[r++] = pre[t++];
            tmp[r++] = pre[i];
            cnt += j - k;
        }
        copy(tmp.begin(), tmp.begin() + r, pre.begin() + left);
        return cnt;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
        return mergeCount(pre, 0, n + 1, lower, upper);
    }
};

//
// Driver code (sample usage)
//
int main() {
    // 674. LCIS
    LCIS lcis;
    vector<int> nums1 = {1, 3, 5, 4, 7};
    cout << "LCIS: " << lcis.findLengthOfLCIS(nums1) << endl; // Output: 3

    // 307. Range Sum Query - Mutable
    vector<int> nums2 = {1, 3, 5};
    NumArray numArray(nums2);
    cout << "sumRange(0,2): " << numArray.sumRange(0, 2) << endl; // 9
    numArray.update(1, 2);
    cout << "sumRange(0,2): " << numArray.sumRange(0, 2) << endl; // 8

    // 327. Count of Range Sum
    CountRangeSum crs;
    vector<int> nums3 = {-2, 5, -1};
    cout << "CountRangeSum: " << crs.countRangeSum(nums3, -2, 2) << endl; // 3

    return 0;
}
