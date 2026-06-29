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
int solve(TreeNode *root,int mx)
{
if(root==NULL) return 0;
int ans=0;
if(root->val>=mx) ans=1;
return ans+solve(root->left,max(mx,root->val))+solve(root->right,max(mx,root->val)); 
}
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};
