vector<vector<int>> dp;
int target,totalSum;
int solve(vector<int> &arr,int curr,int i)
{
if(i==arr.size()) return curr==target;
if(dp[i][curr+totalSum]!=INT_MIN) return dp[i][curr+totalSum];
// you can simply leave this number 
int a=solve(arr,curr+arr[i],i+1);
// or you can remove this number from target
int b=solve(arr,curr-arr[i],i+1);
return dp[i][curr+totalSum]=a+b;
}
class Solution {
public:
int findTargetSumWays(vector<int>& arr, int t) {
dp.clear();
int n=arr.size();
int sum=accumulate(arr.begin(),arr.end(),0);
target=t;
totalSum=sum;
dp.assign(n,vector<int>(sum*2+1,INT_MIN));
return solve(arr,0,0);
}
};
