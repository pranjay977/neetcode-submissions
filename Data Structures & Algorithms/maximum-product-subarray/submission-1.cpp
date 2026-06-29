class Solution {
public:
int maxProduct(vector<int>& arr) {
int n=arr.size();        
vector<long long> prefix(n);
vector<long long> suffix(n);
long long ans=1;
long long MOD=INT_MAX-1;
for(int i=0;i<arr.size();++i)
{
ans*=arr[i]%MOD;
prefix[i]=ans;
if(!ans) ans=1;
}
ans=1;
for(int i=n-1;i>=0;--i)
{
ans*=arr[i]%MOD;
suffix[i]=ans;
if(!ans) ans=1;
}
long long mx=arr[0];
for(int i=0;i<arr.size();i++)
{
mx=max({mx,(long long)arr[i],prefix[i],suffix[i]});
}
return mx;
    }
};
