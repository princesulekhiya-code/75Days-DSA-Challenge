class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int mid) {
        int cnt = 1, curr = 0;
        for (int n : nums) {
            if (curr + n > mid) {
                cnt++;
                curr = 0;
            }
            curr += n;
        }
        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0), ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return ans;
    }
};
