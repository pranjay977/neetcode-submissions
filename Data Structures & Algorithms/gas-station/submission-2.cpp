class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
int cost_sum=accumulate(cost.begin(),cost.end(),0);
int gas_sum=accumulate(gas.begin(),gas.end(),0);
if(cost_sum>gas_sum) return -1;
int n=gas.size();
int ans=0;
int curr=0;
for(int i=0;i<2*n;++i)
{
curr-=cost[i%n];
curr+=gas[i%n];
if(curr<=0) 
{
    ans=(i+1)%n;
    curr=0;
}
}
return ans;
    }
};
