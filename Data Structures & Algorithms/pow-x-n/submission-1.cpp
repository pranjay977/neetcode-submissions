vector<double> dp;
double solve(double base,int pow)
{
if(pow<=1) return base;
if(dp[pow]!=-1) return dp[pow];
dp[pow]=(solve(base,pow/2)*solve(base,pow/2));
if(pow%2) dp[pow]*=base;
return dp[pow];
}

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
    dp.assign(abs(n)+1,-1);
double k=solve(x,abs(n));
if(n<0) return 1/k;
return k;   
    }
};
