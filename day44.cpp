# 🚀 75 Days DSA Challenge – Day 44 | Diwali Special ✨

## 📚 Topic: Binary Trees & Traversal Reconstruction  
Even though it’s **Diwali 🪔**, I stayed consistent and solved one important tree problem that deepened my understanding of recursive structures and traversal logic.

---

### 🧩 Problem Solved:
**106. Construct Binary Tree from Inorder and Postorder Traversal**  
🔗 [View Problem on LeetCode](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

---

### 💻 C++ Code:

```cpp
// LeetCode 106: Construct Binary Tree from Inorder and Postorder Traversal
// Author: Prince Sulekhiya
// Day 44 – Diwali Special 🎇

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        int postIndex = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, postIndex, inMap);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int &postIndex, unordered_map<int,int>& inMap) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inMap[rootVal];

        // Build right before left (because of postorder traversal)
        root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex, inMap);
        root->left = build(inorder, postorder, inStart, inIndex - 1, postIndex, inMap);

        return root;
    }
};

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);
    cout << "Tree constructed successfully for Diwali Special! 🎇" << endl;
    return 0;
}
