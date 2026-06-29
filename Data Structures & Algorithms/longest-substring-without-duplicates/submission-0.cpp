class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     map<char,int> mp;
     int ans=0;
     int si=0;
     for(int i=0;i<s.size();i++)
     {
      mp[s[i]]++;
      while(mp[s[i]]>1) 
      {
      if(--mp[s[si]]==0) mp.erase(s[si]);
      si++;
      }
      ans=max(ans,i-si+1);
     }
     return ans;   
    }

};
