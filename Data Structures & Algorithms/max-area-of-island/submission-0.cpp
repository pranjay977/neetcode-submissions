int dr[]={1,-1,0,0};
int dc[]={0,0,-1,1};
int n,m;
vector<vector<int>> vis;
int dfs(vector<vector<int>> &arr,int r,int c)
{
vis[r][c]=1;
int ans=0;
for(int i=0;i<4;i++)
{
int nr=dr[i]+r;
int nc=dc[i]+c;
if(nr>=0 &&  nc>=0 && nr<n && nc<m && arr[nr][nc]==1 && vis[nr][nc]==0) 
{
    ans+=(1+dfs(arr,nr,nc));
}
}
return ans;
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        n=arr.size();
        m=arr[0].size();
        int ans=0;
        vis.assign(arr.size(),vector<int>(arr[0].size(),0)); 
        for(int i=0;i<arr.size();i++)
        {
        for(int j=0;j<arr[0].size();j++) 
        {
        if(arr[i][j]==1 && vis[i][j]==0)
        {
        int ac=1+dfs(arr,i,j);
        ans=max(ac,ans);
        }
        }
        }
        return ans;
        
        
    }
};
