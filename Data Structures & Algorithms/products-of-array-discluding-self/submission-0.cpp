class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
            int MOD=1e9+7;
            vector<int> prefix(arr.size());
            vector<int> suffix(arr.size());
            int prd=1;
            for(int i=0;i<arr.size();i++)
            {
             prd=(prd*arr[i])%MOD;
             prefix[i]=prd;
            }
            prd=1;
            for(int i=arr.size()-1;i>=0;i--)
            {
             prd=(prd*arr[i])%MOD;
             suffix[i]=prd;
            }
            vector<int> ans(arr.size());
            for(int i=0;i<arr.size();i++)
            {
            int res=1;
            if(i>0) res=(res*prefix[i-1])%MOD;
            if(i<(arr.size()-1))  res=(res*suffix[i+1])%MOD; 
            ans[i]=res;
            }
            return ans;
            
            
    }
};
