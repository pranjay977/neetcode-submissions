

vector<vector<string>> ans;
vector<int> positive;
vector<vector<char>> vis;
vector<int> col;
vector<int> negative;
int n;
void solve(int r)
{
if(r==n) 
{
vector<string> result;
for(int i=0;i<n;++i)
{
string res="";
for(int j=0;j<n;++j) res+=vis[i][j];
result.push_back(res);
}
ans.push_back(result);
return ;
}

for(int i=0;i<n;++i)
{
int index=r-i+n;
if(col[i] || positive[r+i] || negative[index]) continue;
col[i]=1;
positive[i+r]=1;
negative[index]=1;
vis[r][i]='Q';
solve(r+1);
col[i]=0;
positive[i+r]=0;
negative[index]=0;
vis[r][i]='.';
}
}

class Solution {
public:
vector<vector<string>> solveNQueens(int N) {
n=N;
col.assign(n, 0);
positive.assign(2 * n, 0);
negative.assign(2 * n + 1, 0);
vis.assign(n, vector<char>(n, '.'));
ans.clear();
solve(0);
return ans;
}
};
