void dfs(vector<vector<int>> &arr,vector<bool> &vis,int i)
{
cout<<i<<endl;
vis[i]=true;
for(int e:arr[i])
{
if(vis[e]==false)
{
dfs(arr,vis,e);
}
}
}
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& abc) {
        vector<vector<int>> arr(n);        
        for (const auto& edge : abc) {
            arr[edge[0]].push_back(edge[1]);
            arr[edge[1]].push_back(edge[0]);
        }
       vector<bool> vis(n+1,false);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
        if(vis[i]==false)
        {
        cnt++;
        dfs(arr,vis,i);
        }
        }
return cnt;
    }
};
