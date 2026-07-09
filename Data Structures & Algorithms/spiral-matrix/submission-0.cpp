class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int dr[]={0,1,0,-1};
int dc[]={1,0,-1,0};
int n=arr.size(),m=arr[0].size();
int prevC=0,prevR=0;
vector<int> ans;
ans.push_back(arr[0][0]);
int i=0;
vector<vector<int>> vis(n,vector<int>(m));
vis[0][0]=1;
int k=arr.size()*arr[0].size()-1;

while(k)
{
int r=dr[i]+prevR;
int c=dc[i]+prevC;
if(c<0 || c>=m || r<0 || r>=n || vis[r][c]) 
{
	i=(i+1)%4;
		
	c=prevC+dc[i];
	r=prevR+dr[i];
}	
ans.push_back(arr[r][c]);
vis[r][c]=1;
prevR=r;
prevC=c;

k--;
}
return ans;

    }
};
