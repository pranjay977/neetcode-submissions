vector<vector<int>> dp;
int solve(vector<int> &arr,int curr,int i)
{
if(i>=arr.size()) return 0;
if(dp[i][curr]!=-1) return dp[i][curr];
int a=0;
int b=0;
if(curr)
{
a=max(solve(arr,curr,i+1),solve(arr,!curr,i+1)-arr[i]);
// means you can buy
}
else 
{
b=max(solve(arr,curr,i+1),solve(arr,!curr,i+2)+arr[i]);
}
return dp[i][curr]=max(a,b);
}



class Solution {
public:
    int maxProfit(vector<int>& arr) {
dp.assign(arr.size(),vector<int>(2,-1));
return solve(arr,1,0);
    }
};
