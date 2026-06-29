vector<vector<int>> dp;
bool solve(string str,map<string,int> &mp,int si,int i)
{
if(si==str.size()) return true;
if(i>=str.size()) return false;
if(dp[si][i]!=-1) return dp[si][i];
string sub=str.substr(si,i-si+1);
bool a=false;
if(mp.find(sub)!=mp.end())
{
a=solve(str,mp,i+1,i+1);
}
bool b=solve(str,mp,si,i+1);
return dp[si][i]=max(a,b);
}
class Solution {
public:
    bool wordBreak(string str, vector<string>& a) {
        map<string,int> mp;
        dp.assign(str.size()+1,vector<int>(str.size()+1,-1));
        for(string s:a) mp[s]++;
        return solve(str,mp,0,0);
    }
};
