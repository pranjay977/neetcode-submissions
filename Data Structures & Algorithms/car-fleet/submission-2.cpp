class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> arr;
        for(int i=0;i<speed.size();i++) arr.push_back({position[i],speed[i]});
        sort(arr.begin(),arr.end());
        int n=arr.size();
        double mx=(double)(target-arr[n-1].first)/arr[n-1].second;
        int ans=1;
        int cnt=1;
        for(int i=n-2;i>=0;i--)
        {
            double a=(double)(target-arr[i].first)/arr[i].second;
            if(a>mx) 
            {
            mx=a;
            cnt++;
            }
        }
        return cnt;
    } 
};
