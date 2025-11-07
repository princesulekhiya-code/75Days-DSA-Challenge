class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
        return mergeCount(pre, 0, n, lower, upper);
    }

    int mergeCount(vector<long long>& pre, int left, int right, int lower, int upper) {
        if (left >= right) return 0;
        int mid = (left + right) / 2;
        int count = mergeCount(pre, left, mid, lower, upper)
                  + mergeCount(pre, mid + 1, right, lower, upper);

        int l = mid + 1, r = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (l <= right && pre[l] - pre[i] < lower) l++;
            while (r <= right && pre[r] - pre[i] <= upper) r++;
            count += r - l;
        }

        vector<long long> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (pre[i] < pre[j]) temp[k++] = pre[i++];
            else temp[k++] = pre[j++];
        }
        while (i <= mid) temp[k++] = pre[i++];
        while (j <= right) temp[k++] = pre[j++];
        for (int t = 0; t < temp.size(); t++) pre[left + t] = temp[t];

        return count;
    }
};
