class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int cnt=0;
            int mx=INT_MIN;
            for(int e:nums)
            {
            cnt+=e;
            mx=max(cnt,mx);
            if(cnt<0) cnt=0;
            }
            return mx;
    }
};
