#include <bits/stdc++.h>
using namespace std;

// -------------------------
// 410. Split Array Largest Sum
// -------------------------
class SplitArrayLargestSum {
public:
    bool canSplit(vector<int>& nums, int m, int mid) {
        int count = 1, sum = 0;
        for (int n : nums) {
            if (sum + n > mid) {
                count++;
                sum = n;
                if (count > m) return false;
            } else {
                sum += n;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, m, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// -------------------------
// 378. Kth Smallest Element in a Sorted Matrix
// -------------------------
class KthSmallestMatrix {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (count < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

// -------------------------
// 1011. Capacity To Ship Packages Within D Days
// -------------------------
class ShipCapacity {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int used = 1, total = 0;
        for (int w : weights) {
            if (total + w > capacity) {
                used++;
                total = w;
                if (used > days) return false;
            } else {
                total += w;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShip(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// -------------------------
// Driver code for testing
// -------------------------
int main() {
    // Example test for Split Array Largest Sum
    vector<int> nums = {7,2,5,10,8};
    int m = 2;
    SplitArrayLargestSum sol1;
    cout << "Split Array Largest Sum: " << sol1.splitArray(nums, m) << "\n";

    // Example test for Kth Smallest in Matrix
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    int k = 8;
    KthSmallestMatrix sol2;
    cout << "Kth Smallest Element: " << sol2.kthSmallest(matrix, k) << "\n";

    // Example test for Ship Packages
    vector<int> weights = {1,2,3,1,1};
    int days = 4;
    ShipCapacity sol3;
    cout << "Ship Capacity Within Days: " << sol3.shipWithinDays(weights, days) << "\n";

    return 0;
}
