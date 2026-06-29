bool dfs(string str,int diff,int i)
{
if(diff<0) return false;
if(i==str.size()) return diff==0;
if(str[i]==')') return dfs(str,diff-1,i+1);
if(str[i]=='(') return dfs(str,diff+1,i+1);;
return dfs(str,diff+1,i+1) || dfs(str,diff-1,i+1) || dfs(str,diff,i+1);
}
class Solution {
public:
bool checkValidString(string s) 
{
    return dfs(s,0,0);
}
};
