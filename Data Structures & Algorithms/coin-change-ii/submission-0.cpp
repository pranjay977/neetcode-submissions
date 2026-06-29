vector<vector<int>> dp;
int solve(vector<int> &arr,int target,int i)
{
if(target==0) return 1;
if(target<0) return 0;
if(i==arr.size()) return 0;
if(dp[i][target]!=-1) return dp[i][target];
int a=0,b=0;
if(arr[i]<=target)
{
a=solve(arr,target-arr[i],i);
}
b=solve(arr,target,i+1);
return dp[i][target]=a+b;
}
class Solution {
public:
    int change(int amount, vector<int>& arr) {
        dp.assign(arr.size()+1,vector<int>(amount+1,-1));
        return solve(arr,amount,0);
    }
};
