class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
     priority_queue<int> pq;
     for(int e:arr)
     pq.push(e);
     while(pq.size()!=1)
     {
     int a=pq.top();
     pq.pop();
     int b=pq.top();
     pq.pop();
     pq.push(abs(a-b));
    }
    
    return pq.top();

        
    }
};
