class Solution {
public:
    int maxProfit(vector<int>& arr) {
           int mn=arr[0];
           vector<int> smll(arr.size());
           for(int i=0;i<arr.size();i++)
            {
            mn=min(arr[i],mn);
            smll[i]=mn;
            }
           int mx=arr[arr.size()-1];
           vector<int> larg(arr.size());
           for(int i=arr.size()-1;i>=0;i--)
            {
            mx=max(arr[i],mx);
            larg[i]=mx;
            }
            int profit=0;
            for(int i=0;i<arr.size()-1;i++)
            {
            profit=max(profit,larg[i]-smll[i]);
            }
            return profit;
    }
};
