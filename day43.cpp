#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ✅ 103. Binary Tree Zigzag Level Order Traversal
class ZigzagTraversal {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                int index = leftToRight ? i : size - i - 1;
                row[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(row);
        }
        return ans;
    }
};

// ✅ 105. Construct Binary Tree from Preorder and Inorder Traversal
class BuildTree {
public:
    unordered_map<int, int> inorderIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) inorderIndex[inorder[i]] = i;
        int preIndex = 0;
        return helper(preorder, 0, inorder.size() - 1, preIndex);
    }

    TreeNode* helper(vector<int>& preorder, int inStart, int inEnd, int& preIndex) {
        if (inStart > inEnd) return NULL;
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int index = inorderIndex[rootVal];
        root->left = helper(preorder, inStart, index - 1, preIndex);
        root->right = helper(preorder, index + 1, inEnd, preIndex);
        return root;
    }
};

int main() {
    ZigzagTraversal zt;
    BuildTree bt;
    cout << "Day 43 - Binary Tree Zigzag & Build Completed Successfully!" << endl;
    return 0;
}

