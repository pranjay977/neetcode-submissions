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
int k=0;
int solve(TreeNode *root)
{
stack<TreeNode *> stck;
for(TreeNode *j=root;j;j=j->left) stck.push(j);
while(!stck.empty())
{
TreeNode *t=stck.top();
stck.pop();
k--;
if(k==0) return t->val;
if(t->right)
{
for(TreeNode *j=t->right;j;j=j->left) stck.push(j);
}
}
return 0;
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int n) {
     k=n;
     return solve(root);   
    }
};
