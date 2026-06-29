class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
            if(arr.size()%k) return false;
            if(k==1) return true;
        map<int,int> mp;
        for(int e:arr) mp[e]++;
        int cnt=0;
        int prev;
        while(mp.size()!=0)
        {
        if(cnt==0) 
        {
        map<int,int>::iterator it=mp.begin();
        prev=it->first;
        cnt=1;
        }
        if(mp.find(prev+1)==mp.end()) return false;
        else 
        {
        cnt++;
        if(--mp[prev]==0) mp.erase(prev);
        prev++;
        }
        if(cnt%k==0) 
        {
        if(--mp[prev]==0) mp.erase(prev);
        auto it=mp.begin();
        prev=it->first;
        cnt=1;
        }
        }
    return true;
    }
};
