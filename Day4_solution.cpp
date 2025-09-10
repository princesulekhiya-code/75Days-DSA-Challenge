#include <bits/stdc++.h>
using namespace std;

//----------------------------------------
// 643. Maximum Average Subarray I
//----------------------------------------
class Solution_MaxAvg {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        long long maxSum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return (double)maxSum / k;
    }
};

//----------------------------------------
// Allocate Books (Binary Search)
//----------------------------------------
class Solution_AllocateBooks {
public:
    bool isPossible(vector<int>& A, int B, long long mid) {
        int students = 1;
        long long pages = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > mid) return false;
            if (pages + A[i] > mid) {
                students++;
                pages = A[i];
                if (students > B) return false;
            } else {
                pages += A[i];
            }
        }
        return true;
    }

    int books(vector<int>& A, int B) {
        if (B > A.size()) return -1;
        long long low = *max_element(A.begin(), A.end());
        long long high = accumulate(A.begin(), A.end(), 0LL);
        long long res = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(A, B, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)res;
    }
};

//----------------------------------------
// 1877. Minimize Maximum Pair Sum in Array
//----------------------------------------
class Solution_MinPairSum {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, nums[i] + nums[n - 1 - i]);
        }
        return ans;
    }
};

//----------------------------------------
// 34. Find First and Last Position of Element in Sorted Array
//----------------------------------------
class Solution_SearchRange {
public:
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};

//----------------------------------------
// Example main to test locally
//----------------------------------------
int main() {
    // 643 Test
    Solution_MaxAvg s1;
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    cout << "Max Average Subarray: " << s1.findMaxAverage(nums1, 4) << endl;

    // Allocate Books Test
    Solution_AllocateBooks s2;
    vector<int> books = {12, 34, 67, 90};
    cout << "Allocate Books Result: " << s2.books(books, 2) << endl;

    // 1877 Test
    Solution_MinPairSum s3;
    vector<int> nums2 = {3, 5, 4, 2, 4, 6};
    cout << "Minimized Max Pair Sum: " << s3.minPairSum(nums2) << endl;

    // 34 Test
    Solution_SearchRange s4;
    vector<int> nums3 = {5, 7, 7, 8, 8, 10};
    vector<int> ans = s4.searchRange(nums3, 8);
    cout << "First and Last Position: [" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
