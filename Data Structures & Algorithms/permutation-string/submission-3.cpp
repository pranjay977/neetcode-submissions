bool isValid(string a,string b)
{
vector<int> freq1(26,0),freq2(26,0);
for(int i=0;i<a.size();i++) 
{
freq1[a[i]-'a']++;
freq2[b[i]-'a']++;
}
return freq1==freq2;
}
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string str=s1+s1;
        for(int i=0;i<(s2.size()-s1.size())+1;i++)
        {
         string subStr=s2.substr(i,s1.size());
         if(isValid(s1,subStr)) return true;
        }
        return false;
    }
};
