#define INF 2147483647
vector<vector<int>>  solve(vector<vector<int>> &arr,queue<pair<int,int>> q)
{
int n=arr.size(),m=arr[0].size();
vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
int dr[]={1,-1,0,0};
int dc[]={0,0,-1,1};
while(q.empty()==false)
{
auto[r,c]=q.front();q.pop();
if(arr[r][c]==0) dist[r][c]=0;
for(int i=0;i<4;i++)
{
int nr=dr[i]+r;
int nc=dc[i]+c;
if(nr>=0 && nc>=0 && nr<n && nc<m && arr[nr][nc]!=-1)
{
if(dist[nr][nc]>dist[r][c]+1)
{
dist[nr][nc]=dist[r][c]+1;
q.push({nr,nc});
}
}
}
}
for(int i=0;i<dist.size();i++)
{
for(int j=0;j<dist[0].size();j++) if(dist[i][j]==INT_MAX) dist[i][j]=(arr[i][j]==-1)?-1:INF;
}

return dist;
}
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& arr) {
    queue<pair<int,int>> q;
    for(int i=0;i<arr.size();i++)
    {
    for(int j=0;j<arr[0].size();j++) if(arr[i][j]==0) q.push({i,j});
    }
    arr=solve(arr,q);
    }
};

/*
Input: [
  [2147483647,-1,0,2147483647],
  [2147483647,2147483647,2147483647,-1],
  [2147483647,-1,2147483647,-1],
  [0,-1,2147483647,2147483647]
]

[2,1,0,1],
[2,2,1,2],
[1,2,2,3],
[0,1,2,3]


[3,-1,0,1]
[2,2,1,-1]
[1,-1,2,-1]
[0,-1,3,4]
*/