class Solution {
public:
    bool isHappy(int n) {
        map<int,int> mp;
            int sum=0;
            mp[n]++;
            while(true)
            {
            string str=to_string(n);
            sum=0;
            for(char c:str)
            {
            sum+=(c-'0')*(c-'0');
            }
            n=sum;
            if(n==1) break;
            if(mp.find(n)!=mp.end()) return false;
            mp[n]++;
            }
        return true;

    }
};
