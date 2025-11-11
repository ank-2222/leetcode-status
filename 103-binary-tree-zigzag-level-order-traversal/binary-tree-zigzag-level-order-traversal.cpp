/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        queue<TreeNode*> q;

        if (root == NULL)
            return ans;

        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> temp(levelSize);
            for (int i = 0; i < levelSize; i++) {
                int index = leftToRight ? i : levelSize - i - 1;
                TreeNode* curr = q.front();
                q.pop();
                temp[index] = curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            ans.push_back(temp);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};