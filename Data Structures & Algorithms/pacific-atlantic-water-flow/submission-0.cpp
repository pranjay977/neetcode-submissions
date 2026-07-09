
int dr[]={1,-1,0,0};
int dc[]={0,0,-1,1};
int n,m;
void dfs(vector<vector<int>> &arr,vector<vector<int>> &vis,int r,int c)
{
vis[r][c]=1;
for(int i=0;i<4;++i)
{
	int nr=dr[i]+r;
	int nc=dc[i]+c;
	if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && arr[nr][nc]>=arr[r][c]) dfs(arr,vis,nr,nc);
}
}



vector<vector<int>> solve(vector<vector<int>> &arr)
{
	n=arr.size();
	m=arr[0].size();
vector<vector<int>> pacVis(n,vector<int>(m));
vector<vector<int>> atlVis(n,vector<int>(m));


for(int i=0;i<n;++i)  // first column
{
 if(pacVis[i][0]==0) dfs(arr,pacVis,i,0);
}
for(int i=0;i<m;++i) // first row 
{
 if(pacVis[0][i]==0) dfs(arr,pacVis,0,i);
}

for(int j=0;j<n;++j)  //  last column
{
 if(atlVis[j][m-1]==0) dfs(arr,atlVis,j,m-1);
	
}
for(int j=0;j<m;++j) // last row 
{
 if(atlVis[n-1][j]==0) dfs(arr,atlVis,n-1,j);
	
}



vector<vector<int>> ans;
for(int i=0;i<n;++i)
{
	for(int j=0;j<m;++j)
	{
        cout<<atlVis[i][j]<<" ";
	if(pacVis[i][j]==1 && atlVis[i][j]==1) ans.push_back({i,j});
	}
cout<<endl;
}
return ans;
}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        return solve(heights);        
    }
};
