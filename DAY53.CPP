class Solution {
public:
    int sumNumbers(TreeNode* root, int current = 0) {
        if (!root) return 0;
        current = current * 10 + root->val;
        if (!root->left && !root->right) return current;
        return sumNumbers(root->left, current) + sumNumbers(root->right, current);
    }
};
