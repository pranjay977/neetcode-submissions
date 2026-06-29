bool isPalindrome(string &str,int st,int en)
{
while(st<en) if(str[st++]!=str[en--]) return false;
return true;
}
void solve(vector<vector<string>> &ans,vector<string> &res,string &str,int i,int j)
{
if(j==str.size() && i==str.size()) 
{
ans.push_back(res);
return;
}
if(j==str.size()) return;
// either we skip this point 
solve(ans,res,str,i,j+1);
// or we partition from this point
if(isPalindrome(str,i,j)) 
{
res.push_back(str.substr(i,j-i+1));
solve(ans,res,str,j+1,j+1);
res.pop_back();
}
}
class Solution {
public:
    vector<vector<string>> partition(string s) { 
    vector<vector<string>> ans;
    vector<string> res;
    solve(ans,res,s,0,0);
    return ans;
}
};
