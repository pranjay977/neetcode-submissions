class Solution {
public:
    int maxArea(vector<int>& arr) {
        int ans=0;
        int e=0;
        int j=arr.size()-1;
        while(e<j)
        {
        int mn=min(arr[e],arr[j]);
        int area=mn*(j-e);
        ans=max(area,ans);
        if(arr[e]<arr[j]) e++;
        else j--;
        }
        return ans;
    }

};
