bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;

            for(int it : adj[node]){
                    if(!vis[it]){
                                if(dfs(it, node, adj, vis)) return true;
                                        }
                                                else if(it != parent) return true;
                                                    }
                                                        return false;
                                                        }


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
         vector<vector<int>> adj(n);
             
                 for(auto &e : edges){
                         int u = e[0];
                                 int v = e[1];
                                         adj[u].push_back(v);
                                                 adj[v].push_back(u);
                                                     }

                                                         vector<int> vis(n,0);
int cnt=0;
                                                             for(int i=0;i<n;i++){
                                                                     if(!vis[i]){
                                                                        if(cnt>0) return false;
                                                                                 if(dfs(i,-1,adj,vis)) return false;
                                                                                         cnt=1;
                                                                                         }
                                                                                             }
                                                                                                 return true;
    }
};
