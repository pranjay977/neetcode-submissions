class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
    struct cmp {
    bool operator()(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b) {
            if(a.first!=b.first) return a.first<b.first;
            int sum1=abs(a.second.first)+abs(a.second.second);
            int sum2=abs(b.second.first)+abs(b.second.second);
            return sum1<sum2;
    }
    };
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp> pq;
        for(int i=0;i<arr.size();i++)
        {
        int x1=arr[i][0];
        int y1=arr[i][1];
        int x2=0;
        int y2=0;
        // dist calculation;
         int a=abs(x1-x2)*abs(x1-x2);
         int b=abs(y1-y2)*abs(y1-y2);
         int dist=sqrt(a+b);
        // dist calc ends
        cout<<x1<<" "<<y1<<" "<<dist<<endl;
        pq.push({dist,{x1,y1}});
        if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.empty()==false)
        {
        vector<int> res;
        res.push_back(pq.top().second.first);
        res.push_back(pq.top().second.second);
        ans.push_back(res);
        pq.pop();
        }
        return ans;
    }
};
