vector<int> dp;
int solve(string s,int i)
{
if(i==s.size()) return 1;
if(i>s.size()) return 0;
if(dp[i]!=-1) return dp[i];
// either you pick one character
if(s[i]=='0') return 0;
int a=solve(s,i+1);
// either you pick two character at once
int b=0;
if((i+1)<s.size() && ((s[i]-'0')*10+(s[i+1]-'0'))<=26)
{
 b=solve(s,i+2);
}
return dp[i]=a+b;
}
class Solution {
public:
    int numDecodings(string s) {
        dp.assign(s.size()+1,-1);
        return solve(s,0);
    }
};
