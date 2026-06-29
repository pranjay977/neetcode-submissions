class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
    int curr=1;
    vector<int> ans;
    for(int j=arr.size()-1;j>=0;j--)
    {
    int sum=(arr[j]+curr);
    curr=sum/10;
    ans.push_back(sum%10);
    }
    if(curr!=0) ans.push_back(curr);
    reverse(ans.begin(),ans.end());
    return ans;
    }
};
