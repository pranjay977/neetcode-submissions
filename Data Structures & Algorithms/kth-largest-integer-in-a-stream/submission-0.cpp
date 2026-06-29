class KthLargest {
public:
        priority_queue<int> pq;
        int k;
    KthLargest(int K, vector<int>& nums) {
        k=K;
        for(int e:nums) pq.push(e);

    }
    
    int add(int val) {
        int j=k;
        pq.push(val);
        priority_queue<int> pq1=pq;
        while(!pq1.empty() && j>1) 
        {
        pq1.pop();
        j--;
        }
        if(pq1.empty()) return 0;
        return pq1.top();
    }
};
