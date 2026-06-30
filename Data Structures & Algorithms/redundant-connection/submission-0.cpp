
class DSU
{
vector<int> parent;
vector<int> rank;
public :
DSU(int cap)
{
rank.resize(cap);
parent.resize(cap);
iota(parent.begin(),parent.end(),0);
}
int find(int x)
{
if(x==parent[x]) return x;
return parent[x]=find(parent[x]);
}
bool merge(int a,int b)
{
int e=find(a);
int f=find(b);
if(e==f) return false;
if(rank[e]>rank[f])
{
parent[f]=e;
}
else if(rank[e]<rank[f])
{
parent[e]=f;
}
else{
parent[e]=f;
rank[e]++;
}
return true;
}
};




class Solution {
public:
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
int n=edges.size();
DSU dsu(n+1);
bool flag=true;
int ans=-1;
for(int i=0;i<n;++i)
{
if(dsu.merge(edges[i][0],edges[i][1])==false)  return edges[i];
}
 return {};
}
};
