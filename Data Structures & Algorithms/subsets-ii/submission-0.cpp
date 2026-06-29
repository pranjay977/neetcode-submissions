set<vector<int>> st;
void solve(vector<int> &arr,vector<int> res,int i)
{
if(i==arr.size())
{
st.insert(res);
return;
}
solve(arr,res,i+1);
res.push_back(arr[i]);
solve(arr,res,i+1);
res.pop_back();
}
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
     st.clear();
    sort(arr.begin(),arr.end());
     solve(arr,{},0);
    vector<vector<int>> ans(st.begin(),st.end());
   return ans;
    }
};
