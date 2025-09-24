#include <bits/stdc++.h>
using namespace std;

// 1️⃣ 34. Find First and Last Position of Element in Sorted Array
class Solution34 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        if (left == nums.end() || *left != target) return {-1, -1};
        return {int(left - nums.begin()), int(right - nums.begin() - 1)};
    }
};

// 2️⃣ 1351. Count Negative Numbers in a Sorted Matrix
class Solution1351 {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int row = m - 1, col = 0, count = 0;
        while (row >= 0 && col < n) {
            if (grid[row][col] < 0) {
                count += (n - col);
                row--;
            } else {
                col++;
            }
        }
        return count;
    }
};

// 3️⃣ 240. Search a 2D Matrix II
class Solution240 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};

// Example usage
int main() {
    // Day 18 Problem 1
    vector<int> nums = {5,7,7,8,8,10};
    Solution34 s34;
    vector<int> res34 = s34.searchRange(nums, 8);
    cout << "Problem 34: [" << res34[0] << "," << res34[1] << "]\n";

    // Day 18 Problem 2
    vector
