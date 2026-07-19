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
using Node=TreeNode;
int ans;
int solve(Node *root)
{
if(root==NULL) return 0;
int left=0,right=0;
if(root->left) left=solve(root->left);
if(root->right) right=solve(root->right);
int curr=root->val;
int val=root->val;
if(root->left) val=max(val,left+curr);
if(root->right) val=max(val,right+curr);
if(root->left && root->right) val=max(val,left+right+curr);
ans=max(ans,val);
return max({curr,curr+left,curr+right});
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return -1;
        ans=root->val;
        solve(root);
        return ans;
    }
};
