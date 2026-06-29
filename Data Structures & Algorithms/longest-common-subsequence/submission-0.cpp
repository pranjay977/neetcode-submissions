vector<vector<int>> dp;
int solve(string a,string b,int i,int j)
{
if(i==0 || j==0) return 0;
if(dp[i][j]!=-1) return dp[i][j];
if(a[i-1]==b[j-1]) 
{
return dp[i][j]=1+solve(a,b,i-1,j-1);
}
return dp[i][j]=max(solve(a,b,i-1,j),solve(a,b,i,j-1));
}
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size()+1,vector<int>(text2.size()+1,-1));
        return solve(text1,text2,text1.size(),text2.size());
    }
};
