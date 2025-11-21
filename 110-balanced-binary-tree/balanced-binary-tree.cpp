/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int solve(TreeNode* root){
        if(root==NULL)return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left ==-1 || right==-1) return -1; //if left or irght subtree is unbalanced
        if(abs(left-right)>1) return -1;  // if difference if greater than 1 then unbalanced

        return max(left,right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root)==-1?false:true;
    }
};