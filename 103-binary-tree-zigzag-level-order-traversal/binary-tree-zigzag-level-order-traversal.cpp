class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int n = q.size();
            deque<int> level;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (leftToRight)
                    level.push_back(node->val);
                else
                    level.push_front(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(vector<int>(level.begin(), level.end()));
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
