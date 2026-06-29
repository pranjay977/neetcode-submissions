class Solution {
public:
    string multiply(string a, string b) {
        vector<int> track(a.size()+b.size()+1);
        int n=track.size()-1;
        int aEnd=0,bEnd=0;
        if(a[0]=='-') aEnd=1;
        if(b[0]=='-') bEnd=1;
        for(int i=a.size()-1;i>=aEnd;i--)
        {
        int curr=0;
        int prd;
        vector<int> v;
        for(int j=b.size()-1;j>=bEnd;j--)
        {
        prd=((a[i]-'0')*(b[j]-'0'))+curr;
        curr=prd/10;
        int toPut=prd%10;
        v.push_back(toPut);
        }
        if(curr!=0)
        {
        v.push_back(curr);
        }
        int k=n;
        curr=0;
        for(int e:v)
        {
        track[k]=track[k]+curr+e;
        curr=track[k]/10;
        track[k]%=10;
        k--;
        }
        if(curr!=0)
        {
        track[k]=curr;
        }
        n--;

    }
    string ans="";
    if(aEnd-bEnd!=0) ans+='-';
    int flag=1;
    for(int e:track)
    {
    if(e==0 && flag) continue;
    else
    {
    if(flag) flag=0;
    ans+=(e+'0');
    }
    }
    if(ans=="" || ans=="-") return "0";
    return ans;
    }
};





/*



   123
   152
   246
5








*/






















