// Day 21 - DSA Challenge
// Problems: 704. Binary Search | 912. Sort an Array | 53. Maximum Subarray

// ---------------------- 704. Binary Search ----------------------
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

// ---------------------- 912. Sort an Array ----------------------
class Solution2 {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }
    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> temp;
        int i = l, j = m + 1;
        while (i <= m && j <= r) {
            if (nums[i] < nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while (i <= m) temp.push_back(nums[i++]);
        while (j <= r) temp.push_back(nums[j++]);
        for (int k = l; k <= r; ++k) nums[k] = temp[k - l];
    }
};

// ---------------------- 53. Maximum Subarray ----------------------
class Solution3 {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currentSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
