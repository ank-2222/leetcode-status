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
private:
    int prev = 0;
    int currentCount = 0;
    int maxCount = 0;
    std::vector<int> modes;

public:
    void helper(TreeNode* root) {
        if (root == NULL)
            return;
        helper(root->left);

        currentCount = (root->val == prev) ? currentCount + 1 : 1;
        if (currentCount == maxCount) { // for multiple modes
            modes.push_back(root->val);
        } else if (currentCount > maxCount) { // if any more frequent mode ,
                                              // then resetting modes
            maxCount = currentCount;
            modes = {root->val};
        }
        prev = root->val;

        helper(root->right);
    }
    vector<int> findMode(TreeNode* root) {

        helper(root);
        return modes;
    }
};