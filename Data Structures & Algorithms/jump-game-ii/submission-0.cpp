class Solution {
public:
    int jump(vector<int>& nums) {
    int i=0;
    int l=0;
    int cnt=0;
    while(i<nums.size()-1)
    {
        int mx=0;
        for(int j=l;j<=i;j++) mx=max(nums[j]+j,mx);
        if(mx==0) return -1;
        l=i+1;
        i=mx;
        cnt++;
    }        
    return cnt;
    }
};
