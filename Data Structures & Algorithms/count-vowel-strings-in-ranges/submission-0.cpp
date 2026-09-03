class Solution {
public:
    vector<int> vowelStrings(vector<string>& arr, vector<vector<int>>& queries) {
     auto is_vowel=[](char a)
{
return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
};
int n=arr.size();
vector<int> prefix(n+1);
int cnt=0;
for(int i=0;i<arr.size();++i)
{
string str=arr[i];
if(is_vowel(str[0]) && is_vowel(str[str.size()-1])) ++cnt;
prefix[i+1]=cnt;
}
vector<int> ans;
for(auto e:queries)
{
ans.push_back(prefix[e[1]+1]-prefix[e[0]]);
}
return ans;   
    }
};