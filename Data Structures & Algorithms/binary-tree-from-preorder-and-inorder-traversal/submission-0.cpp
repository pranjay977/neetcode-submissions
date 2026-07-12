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
int curr;
Node * solve(vector<int> &preorder,vector<int> &inorder,int startAt,int endAt)
{
if(startAt>endAt || curr==inorder.size()) return NULL;
int target=preorder[curr];
int i;
for(i=startAt;i<=endAt;++i) if(inorder[i]==target) break;
if(i>endAt) return NULL;
curr++;
Node *t=new Node(target);
t->left=solve(preorder,inorder,startAt,i-1);
t->right=solve(preorder,inorder,i+1,endAt);
return t;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        curr=0;
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};
