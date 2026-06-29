vector<vector<int>> dp;
int solve(string &a,string &b,string &c,int i,int j,int k)
{
if(k>=c.size()) return 1;
if(i==a.size() && j==b.size()) return 0;
if(dp[i][j]!=-1) return dp[i][j];
int res1=0,res2=0;
if(i<a.size() && a[i]==c[k]) res1=solve(a,b,c,i+1,j,k+1);
if(j<b.size() && b[j]==c[k]) res2=solve(a,b,c,i,j+1,k+1);
return dp[i][j]=max(res1,res2);
}
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        dp.assign(s1.size()+1,vector<int>(s2.size()+1,-1));
        if(s3.size()<s1.size()+s2.size()) return false;
        return solve(s1,s2,s3,0,0,0);
    }
};
