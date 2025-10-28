class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val) {
            ans.push_back(path);
        } else {
            solve(root->left, targetSum - root->val, path, ans);
            solve(root->right, targetSum - root->val, path, ans);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, targetSum, path, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    vector<vector<int>> res = sol.pathSum(root, targetSum);
    cout << "✅ Path Sum II executed successfully for Day 52!" << endl;
    return 0;
}
