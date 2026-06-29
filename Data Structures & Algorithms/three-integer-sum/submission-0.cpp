class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        set<vector<int>> ans;
        for(int i=0;i<arr.size()-1;i++)
        {
        int t=-1*arr[i];
        int e=i+1;
        int j=arr.size()-1;
        while(e<j)
        {
        int sum=arr[e]+arr[j];
        if(sum==t) 
        {
        vector<int> res;
        res.push_back(arr[i]);
        res.push_back(arr[e]);
        res.push_back(arr[j]);
        ans.insert(res);
        e++;
        j--;
        }
        else if(sum<t) e++;
        else j--;
        }
        }  
        vector<vector<int>> v(ans.begin(),ans.end()); 
        return v;
    }
};
