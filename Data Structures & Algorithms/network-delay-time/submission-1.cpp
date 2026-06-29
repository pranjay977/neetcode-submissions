int n;
vector<int> solve(vector<vector<pair<int,int>>> &arr,int src)
{
vector<int> dist(n+1,INT_MAX);
dist[src]=0;
priority_queue<pair<int,int>> q;
q.push({0,src});
while(q.empty()==false)
{
auto[cost,node]=q.top();q.pop();
for(pair<int,int> e:arr[node])
{
if(dist[e.first]>dist[node]+e.second)
{
dist[e.first]=dist[node]+e.second;
q.push({-1*dist[e.first],e.first});
}
}
}
return dist;
}


class Solution 
{
public:
int networkDelayTime(vector<vector<int>>& times, int sz, int k) {
n=sz;
vector<vector<pair<int,int>>> arr(sz+1);
for(vector<int> e:times) arr[e[0]].push_back({e[1],e[2]});
vector<int> dist=solve(arr,k);
int ans=0;
for(int i=1;i<dist.size();i++)
{
ans=max(ans,dist[i]);
}
return (ans==INT_MAX)?-1:ans;
}
};  
