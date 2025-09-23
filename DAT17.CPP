// ===========================================
// File: 34_Find_First_and_Last_Position_of_Element_in_Sorted_Array.cpp
// ===========================================
#include <bits/stdc++.h>
using namespace std;

class Solution34 {
public:
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            } else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
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
            } else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};

// ===========================================
// File: 1351_Count_Negative_Numbers_in_a_Sorted_Matrix.cpp
// ===========================================
class Solution1351 {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int row = m - 1, col = 0;
        int count = 0;

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

// ===========================================
// File: 240_Search_a_2D_Matrix_II.cpp
// ===========================================
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
