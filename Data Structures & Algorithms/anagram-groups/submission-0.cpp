class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
            map<vector<int>,vector<string>> mp;
            for(string s:str)
            {
            vector<int> freq(26,0);
            for(char c:s) freq[c-'a']++;
            mp[freq].push_back(s);
            }
            vector<vector<string>> ans;
            for(auto &pair:mp)
            {
            vector<string> v;
            vector<string> res=pair.second;
            for(string ss:res)
            {
            v.push_back(ss);
            }
            ans.push_back(v);
            }
            return ans;

    }
};
