void solve(vector<int> &arr,vector<vector<int>> &ans,vector<int> &res,int target,int i)
{
if(target==0)
{
ans.push_back(res);
return;
}
if(i>=arr.size() || target<0) return;
for(int j=i;j<arr.size();j++)
{
if(j>i && arr[j]==arr[j-1]) continue;
if(target-arr[j]<0) return;
res.push_back(arr[j]);
solve(arr,ans,res,target-arr[j],j+1);
res.pop_back();
}
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> res;
        solve(arr,ans,res,target,0);
        return ans;
    }
};
