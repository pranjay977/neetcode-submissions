class Solution {
public:
    int characterReplacement(string str, int k) {
        int si=0;
        map<char,int> mp;
        int ans=INT_MIN;
        int maxFreq=0;
        for(int i=0;i<str.size();i++)
        {
        char m=str[i];
        maxFreq=max(maxFreq,++mp[m]);
        if((i-si+1)-maxFreq>k)
        {
        maxFreq=0;
        if(--mp[str[si]]==0) mp.erase(str[si]);
        si++;
        }
        ans=max(ans,i-si+1);
        }
        return ans;
    }
};
