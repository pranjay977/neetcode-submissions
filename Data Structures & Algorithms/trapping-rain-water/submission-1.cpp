class Solution {
public:
    int trap(vector<int>& arr) {
        vector<int> left(arr.size());
        vector<int> right(arr.size());
        int mx=arr[0];
        for(int i=0;i<arr.size();i++)
        {
        mx=max(arr[i],mx);
        right[i]=mx;
        }
         mx=arr[arr.size()-1];
        for(int i=arr.size()-1;i>=0;i--)
        {
        mx=max(arr[i],mx);
        left[i]=mx;
        }
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
        if(left[i]==arr[i] || right[i]==arr[i]) continue;
        int diff=min(left[i],right[i]);
        ans+=(diff-arr[i]);
        }        
        return ans;
    }
};
