string arr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> ans;
void solve(string digits,string str,int i)
{
if(i==digits.size())
{
if(str.size()==0) return;
ans.push_back(str);
return;
}
for(char c:arr[digits[i]-'0'])
{
str.push_back(c);
solve(digits,str,i+1);
str.pop_back();
}
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        ans.clear();
        
        solve(digits,"",0);
        return ans;            
    }
};
