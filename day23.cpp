/*
Day 23 – 80-Day DSA Challenge
Solved Problems: 3

1️⃣ Problem: 37. Sudoku Solver (Hard)
Description: Solve a Sudoku puzzle by filling empty cells such that each digit 1-9 occurs exactly once in each row, column, and 3x3 sub-box. The board is guaranteed to have a unique solution.
Tags: #Backtracking #DFS #Matrix #LeetCode #C++ #DSA

2️⃣ Problem: 200. Number of Islands (Medium)
Description: Given a 2D grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
Tags: #DFS #BFS #Matrix #Graphs #LeetCode #C++ #DSA

3️⃣ Problem: 112. Path Sum (Easy)
Description: Given a binary tree and a target sum, determine if the tree has a root-to-leaf path such that the sum of the values along the path equals the target sum.
Tags: #Trees #DFS #Recursion #LeetCode #C++ #DSA
*/

#include <bits/stdc++.h>
using namespace std;

// ================= Problem 37: Sudoku Solver =================
class SolutionSudoku {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == c) return false;
            if(board[i][col] == c) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// ================= Problem 200: Number of Islands =================
class SolutionIslands {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

// ================= Problem 112: Path Sum =================
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SolutionPathSum {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right) return root->val == targetSum;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
