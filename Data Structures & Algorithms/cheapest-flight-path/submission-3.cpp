class Solution {
public:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
vector<vector<pair<int,int>>> arr(n);
for(vector<int> e:flights) arr[e[0]].push_back({e[1],e[2]});
vector<int> dist(n,INT_MAX);
dist[src]=0;
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
pq.push({k,{src,0}});
while(pq.empty()==false)
{
auto[stops,ss]=pq.top();pq.pop();
// if(ss.first==dest) continue;
// if(dist[ss.first]<stops) continue;
cout<<stops<<" "<<ss.first<<endl;
for(auto e:arr[ss.first])
{
if(dist[e.first]>dist[ss.first]+e.second && (stops-1>-1 || (stops==0 && e.first==dest)) )
{
dist[e.first]=dist[ss.first]+e.second;
pq.push({stops-1,{e.first,dist[e.first]}});
}
}
}
for(int e:dist) cout<<e<<" ";
cout<<endl;
return (dist[dest]==INT_MAX)?-1:dist[dest];
    }
};
