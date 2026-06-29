class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> stck;
        for(int i=0;i<k;i++) 
        {
        while(stck.empty()==false && arr[stck.back()]<arr[i]) stck.pop_back();
        stck.push_back(i);
        }
        vector<int> ans;
        ans.push_back(arr[stck.front()]);
        for(int i=k;i<arr.size();i++)
        {
        while(stck.empty()==false && i-stck.front()>=k) stck.pop_front();
        while(stck.empty()==false && arr[stck.back()]<arr[i]) stck.pop_back();
        stck.push_back(i);
        ans.push_back(arr[stck.front()]);
        }
        return ans;
    }
};
