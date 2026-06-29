int dr[]={1,-1,0,0};
int dc[]={0,0,-1,1};
int n,m;
vector<vector<int>> vis;
void dfs(vector<vector<char>> &arr,int r,int c)
{
vis[r][c]=1;
for(int i=0;i<4;i++)
{
int nr=dr[i]+r;
int nc=dc[i]+c;
if(nr>=0 &&  nc>=0 && nr<n && nc<m && arr[nr][nc]=='1' && vis[nr][nc]==0) dfs(arr,nr,nc);
}
}
class Solution {
public:
    int numIslands(vector<vector<char>>& arr) {
        // simple bfs code nothing special
        n=arr.size();
        m=arr[0].size();
        int cnt=0;
        vis.assign(arr.size(),vector<int>(arr[0].size(),0)); 
        for(int i=0;i<arr.size();i++)
        {
        for(int j=0;j<arr[0].size();j++) 
        {
        if(arr[i][j]=='1' && vis[i][j]==0)
        {
        dfs(arr,i,j);
        cnt++;
        }
        }
        }
        return cnt;
        
     }
};
