#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2 || root1->val != root2->val) return false;

        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};

int main() {
    Solution sol;

    // Example Test Case
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(8);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(5);
    root2->left->right = new TreeNode(6);
    root2->right->right->left = new TreeNode(8);
    root2->right->right->right = new TreeNode(7);

    cout << (sol.flipEquiv(root1, root2) ? "✅ Trees are Flip Equivalent" : "❌ Trees are Not Flip Equivalent") << endl;
    cout << "🌳 Day 47 – Flip Equivalent Binary Trees Completed Successfully!" << endl;

    return 0;
