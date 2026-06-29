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
public:
    vector<int> rightSideView(TreeNode* root) {
        int insertionCount=1;
        int x=0;
        int j=1;
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);     
        while(!q.empty())
        {
        j=1;
        x=0;
        int sz=q.size();
        while(j<=insertionCount)
        {
        TreeNode *t=q.front();
        q.pop();
        if(sz==1) ans.push_back(t->val);
        if(t->left!=NULL) 
        {
            q.push(t->left);
            x++;
        }
        if(t->right!=NULL) 
        {
            q.push(t->right);
            x++;
        }
        j++;
        sz--;
        }
        insertionCount=x;
        }
        return ans;
    }
};
