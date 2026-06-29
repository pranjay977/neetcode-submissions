class Solution {
public:
    vector<int> partitionLabels(string s) {
    vector<pair<int,int>> freq(26,{-1,-1});
    for(int i=0;i<s.size();i++) 
    {
       if(freq[s[i]-'a'].first==-1) freq[s[i]-'a'].first=i;
        freq[s[i]-'a'].second=i;
    }
    sort(freq.begin(),freq.end());
    int i=0;
    while(freq[i].first==-1) i++;
    vector<pair<int,int>> ans;
    for(auto &pair:freq) 
    {
    cout<<pair.first<<" "<<pair.second<<endl;
    }
    int st=freq[i].first;
    int en=freq[i].second;
    while(i<freq.size())
    {
    int k=i;
    while(i<freq.size() && freq[i].first<en) 
    {
    en=max(en,freq[i].second);
    i++;
    }
    ans.push_back({st,en});
    if(k==i) i++;
    if(i<freq.size())
    {
    st=freq[i].first;
    en=freq[i].second;
    }
    }
    vector<int> res;
    for(auto &pair:ans) res.push_back(pair.second-pair.first+1);
    return res;
}
};
