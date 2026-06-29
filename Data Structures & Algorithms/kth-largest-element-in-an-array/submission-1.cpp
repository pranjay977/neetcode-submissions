class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
    struct cmp
    {
    bool operator()(int a,int b)
    {
    return a>b;
    }
    };
      priority_queue<int,vector<int>,cmp> pq;
        for(int i=0;i<arr.size();i++)
        {
        pq.push(arr[i]);
        if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
