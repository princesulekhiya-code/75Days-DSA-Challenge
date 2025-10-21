#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, int> inorderIndex;
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int& postIndex) {
        if (inStart > inEnd) return NULL;
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int idx = inorderIndex[rootVal];
        root->right = build(inorder, idx + 1, inEnd, postorder, postIndex);
        root->left = build(inorder, inStart, idx - 1, postorder, postIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) inorderIndex[inorder[i]] = i;
        int postIndex = postorder.size() - 1;
        return build(inorder, 0, inorder.size() - 1, postorder, postIndex);
    }
};

int main() {
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = sol.buildTree(inorder, postorder);
    cout << "✅ Binary Tree constructed successfully for Day 45!" << endl;
    return 0;
}
