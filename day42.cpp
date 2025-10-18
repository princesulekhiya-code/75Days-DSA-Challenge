// 145. Binary Tree Postorder Traversal
class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;
        while(root || !st.empty()) {
            if(root) {
                st.push(root);
                root = root->left;
            } else {
                TreeNode* node = st.top();
                if(node->right && lastVisited != node->right) {
                    root = node->right;
                } else {
                    res.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }
        return res;
    }
};

// 102. Binary Tree Level Order Traversal
class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> level;
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
