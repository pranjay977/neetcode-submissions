class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
     map<int,int> mp;
     for(int e:arr) mp[e]++;
     vector<int> ans;
     priority_queue<pair<int,int>> pq; 
    for(map<int,int>::iterator i=mp.begin();i!=mp.end();++i)
     {
     pq.push({i->second,i->first});
     }   
     while(!pq.empty() && k)
     {
     ans.push_back(pq.top().second);
    pq.pop();
    k--; 
    }
     return ans;
    }
};
