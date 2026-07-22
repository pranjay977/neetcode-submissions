class Solution {
public:
int minCostConnectPoints(vector<vector<int>>& points) 
{
int n=points.size();
vector<vector<pair<int,int>>> arr(n);
for(int i=0;i<n;++i)
{
int a=points[i][0];
int b=points[i][1];

for(int j=i+1;j<n;++j)
{
if(j==i) continue;
int c=points[j][0];
int d=points[j][1];
int cost=(abs(a-c)+abs(b-d));
arr[i].push_back({cost,j});
arr[j].push_back({cost,i});
}
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
pq.push({0,0});
vector<int> vis(n);
//vector<int> dist(n);
//dist[0]=0;
int ans=0;
while(pq.empty()==false)
{
auto[dist,r]=pq.top();pq.pop();
if(vis[r]) continue;
ans+=dist;
vis[r]=1;
for(auto e:arr[r])
{
if(!vis[e.second])  pq.push({e.first,e.second});
}
}
return ans;
}

};
