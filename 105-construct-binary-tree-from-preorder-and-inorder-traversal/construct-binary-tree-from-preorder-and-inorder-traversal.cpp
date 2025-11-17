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
    int preIdx = 0;
    unordered_map<int, int> inIndex; // value -> index in inorder
    vector<int>* prePtr = nullptr;
    TreeNode* solve(int left, int right) {
        if (left > right)
            return nullptr;
        int rootVal = (*prePtr)[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inIndex[rootVal];
        root->left = solve(left, mid - 1);
        root->right = solve(mid + 1, right);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() ||
            preorder.size() != inorder.size())
            return nullptr;

        for (int i = 0; i < inorder.size(); i++) {
            inIndex[inorder[i]] = i;
        }

        preIdx = 0;
        prePtr = &preorder;
        return solve(0, (int)inorder.size() - 1);
    }
};