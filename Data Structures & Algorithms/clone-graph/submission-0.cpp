/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
void solve(map<int,Node *> &mp,Node *nn)
{

        int val=nn->val;
        Node *newNode=new Node(val);
        mp[val]=newNode;
        for(auto e:nn->neighbors)
        {
        if(mp.find(e->val)==mp.end()) solve(mp,e);
        newNode->neighbors.push_back(mp[e->val]);
}
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        map<int,Node *> mp;
        int val=node->val;
        Node *root=new Node(val);
        mp[val]=root;
        for(auto e:node->neighbors)
        {
        if(mp.find(e->val)==mp.end()) solve(mp,e);
        root->neighbors.push_back(mp[e->val]);
        }
    return root;
    }
};
