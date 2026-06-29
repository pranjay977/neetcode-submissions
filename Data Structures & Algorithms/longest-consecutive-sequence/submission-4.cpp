class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()==0) return 0;
        map<int,int> mp;
        for(int e:arr) mp[e]++;
        int prev=-1;
        int ans=1;
        int cnt=-1;
        for(auto &pair:mp)
        {
        if(cnt!=-1 && pair.first-prev==1) cnt++;
        else cnt=1;
        prev=pair.first;
        ans=max(cnt,ans);
        }
        return ans;
        
    }
};
