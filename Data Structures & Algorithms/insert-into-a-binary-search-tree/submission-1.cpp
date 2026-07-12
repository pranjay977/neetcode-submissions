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
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new Node(val);
        Node *t=root;
        while(t)
        {
        if(t->val>val)
        {
        if(t->left==NULL) 
        {
        t->left=new Node(val);
        break;
        }
        else t=t->left;
        }
        else
        {
        if(t->right==NULL) 
        {
        t->right=new Node(val);
        break;
        }
        else t=t->right;
        }
        }
        return root;
    }
};