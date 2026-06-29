class Solution {
public:
    int reverse(int x) {
           string str=to_string(x);
            int flag=1;
            if(str[0]=='-') flag=-1;
            std::reverse(str.begin(),str.end());
            long long ans=0;
            int fnd=0;
            for(char c:str)
            {
            if(c=='-') continue;
            if(c=='0' && fnd==0) continue;
            else
            {
            ans=(ans*10)+c-'0';
            if(ans>INT_MAX || -1*ans<INT_MIN) return 0;
            fnd=1;
            }
            }
        return ans*flag; 

    }
};
