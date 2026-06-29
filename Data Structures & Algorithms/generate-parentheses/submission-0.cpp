vector<string> ans;
void solve(int op,int cl,string str)
{
if(op==0 && cl==0) 
{
    ans.push_back(str);
    return;
}
if(op>cl) return;
if(op>0)
{
str.push_back('(');
solve(op-1,cl,str);
str.pop_back();
}
if(cl>0)
{
str.push_back(')');
solve(op,cl-1,str);
str.pop_back();
}
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        solve(n,n,"");
        return ans;
    }
};
