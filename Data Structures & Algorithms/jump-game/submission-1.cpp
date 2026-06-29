class Solution {
public:
    bool canJump(vector<int>& nums) {
    int i=0;
    int l=0,r=0;
    while(i<nums.size()-1)
    {
    int mx=0;
    for(int j=l;j<=i;j++) 
    {
    mx=max(nums[j]+j,mx);
    }
    if(mx==0) return false;
    l=i+1;
    i=mx;
    }
    return true;
    }
};
