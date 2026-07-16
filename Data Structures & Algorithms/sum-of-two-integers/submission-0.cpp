class Solution {
public:
    int getSum(int a, int b) {
    int ans=0;
    for(int i=0;i<32;++i)
    {
    if((a&(1<<i)) && (b&(1<<i)))
    {
    int k=(1<<i);
    ans+=(k*2);
    }
    else if((a&(1<<i)) || (b&(1<<i))) ans+=(1<<i);
    
    }
    return ans;
    }
};

    


    // 0 0 1 0 0 
    // 0 0 1 1 1
    // 0 1 0 1 1 
    
