vector<int> nextGreater(vector<int> arr)
{
vector<int> ans(arr.size(),-1);
stack<int> stck;
for(int j=arr.size()-1;j>=0;j--)
{
while(!stck.empty() && arr[stck.top()]<=arr[j]) stck.pop();
if(!stck.empty()) 
{
ans[j]=stck.top();
}
stck.push(j);
}
return ans;
}
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
    vector<int> nextG=nextGreater(arr);      
    vector<int> ans(arr.size(),0);
    for(int i=0;i<arr.size();i++)
    {
    if(nextG[i]!=-1) ans[i]=nextG[i]-i;
    }
    return ans;
    }
};
