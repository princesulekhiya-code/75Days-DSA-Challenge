🚀 75 Days DSA Challenge – Day 39

📘 Topic: Matrix & Subarray Optimization (Prefix Sum + Set + Kadane’s Extension)
💻 Platform: LeetCode

🧩 Problem Solved:

1️⃣ 363. Max Sum of Rectangle No Larger Than K

Approach:

Used 2D Prefix Sum and compressed each pair of columns into a 1D array.

Applied Kadane’s algorithm variation with an ordered set to maintain prefix sums.

Used binary search (set.lower_bound()) to find the best subarray sum ≤ k efficiently.

🧠 Key Concepts:

Prefix Sum in 2D Arrays

Kadane’s Algorithm Adaptation

Ordered Set / Tree-Based Search for range optimization

Matrix compression technique

⚙️ Code (C++):
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        for (int left = 0; left < n; ++left) {
            vector<int> rowSum(m, 0);
            for (int right = left; right < n; ++right) {
                for (int i = 0; i < m; ++i)
                    rowSum[i] += matrix[i][right];
                set<int> s;
                s.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for (int sum : rowSum) {
                    curSum += sum;
                    auto it = s.lower_bound(curSum - k);
                    if (it != s.end())
                        curMax = max(curMax, curSum - *it);
                    s.insert(curSum);
                }
                res = max(res, curMax);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,0,1},{0,-2,3}};
    int k = 2;
    cout << sol.maxSumSubmatrix(matrix, k);
    return 0;
}

🧾 Output:
2

🏁 Learning Summary:

Efficiently combined 2D prefix sum, Kadane’s logic, and ordered sets to solve a complex optimization problem.
Learned how to handle matrix compression and perform range queries with logarithmic efficiency.

🏷️ #Day39 #DSA #LeetCode #C++ #PrefixSum #Matrix #ProblemSolving #CodingChallenge #100DaysOfCode #princeSulekhiya
