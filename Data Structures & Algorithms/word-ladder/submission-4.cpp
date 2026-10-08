

class Solution {
public:
int ladderLength(string startWord,string endWord, vector<string>& collection)
{
if(!ranges::contains(collection,endWord)) return 0;
set<string> arr(collection.begin(),collection.end());
priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
pq.push({1,startWord});
char c;
map<string,int> dist;
dist[startWord]=1;
while(pq.empty()==false)
{
auto[cost,word]=pq.top();pq.pop();
if(word==endWord) return cost;
for(int i=0;i<word.size();++i)
{
char original=word[i];
for(c='a';c<='z';++c)
{
word[i]=c;
if(arr.find(word)!=arr.end()) 
{
    if(dist.find(word)==dist.end() || dist[word]>cost+1)
    {
        dist[word]=cost+1;
        
    pq.push({cost+1,word});
}
}
}
word[i]=original;
}
}
return 0;
}
};
