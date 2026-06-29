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
 bool solve(TreeNode *root,int mn,int mx)
 {
 if(root==NULL) return true;
 if(root->val>=mx || root->val<=mn) return false;
 return min(solve(root->left,mn,root->val),solve(root->right,root->val,mx));        
 }
class Solution {
public:
    bool isValidBST(TreeNode* root) {
            return solve(root,INT_MIN,INT_MAX);
    }
};
