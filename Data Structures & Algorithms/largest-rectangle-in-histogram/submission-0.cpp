vector<int> prevSmallerElem(vector<int> &arr)
{
vector<int> ans(arr.size());
stack<int> stck;
for(int i=0;i<arr.size();i++)
{
while(!stck.empty() && arr[stck.top()]>=arr[i]) stck.pop();
if(!stck.empty()) ans[i]=stck.top();
else ans[i]=-1;
stck.push(i);
}
return ans;
}
vector<int> nextSmallerElem(vector<int> &arr)
{
vector<int> ans(arr.size());
stack<int> stck;
for(int i=arr.size()-1;i>=0;i--)
{
while(!stck.empty() && arr[stck.top()]>=arr[i]) stck.pop();
if(!stck.empty()) ans[i]=stck.top();
else ans[i]=arr.size();
stck.push(i);
}
return ans;
}
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
    vector<int> prevSmaller=prevSmallerElem(arr);
    vector<int> nextSmaller=nextSmallerElem(arr);
    int ans=0;
    for(int i=0;i<arr.size();i++){
        int mn;
        int dist;
        mn=arr[i];
        dist=(nextSmaller[i]-prevSmaller[i])-1;
        ans=max(ans,mn*dist);

    }    
    return ans;
    }
};
