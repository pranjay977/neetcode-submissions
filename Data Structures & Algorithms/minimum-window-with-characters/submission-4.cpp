class Solution {
public:
    string minWindow(string arr, string t) {
    map<char,int> freq;
    for(char c:t) freq[c]++;
    map<char,int> mp;
    int need=freq.size();
    int curr=0;
    int si=0;
    int ans=INT_MAX;
    int st=0,en=0;
    for(int i=0;i<arr.size();i++)
    {
    char c=arr[i];
    if(freq[c])  if(++mp[c]==freq[c]) curr++;
    cout<<curr<<endl;
    while(curr==need)
    {
    if((i-si+1)<ans)
    {
    st=si;
    en=i;
    ans=i-si+1;
    }
    char m=arr[si];
    if(freq[m] && --mp[m]<freq[m]) curr--;
    si++;
    }
    } 
    if(ans==INT_MAX) return "";
    return arr.substr(st,en-st+1);
    }
};
