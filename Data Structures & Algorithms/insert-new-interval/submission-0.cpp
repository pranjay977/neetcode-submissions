
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& res) {
            arr.push_back(res);
            sort(arr.begin(),arr.end());
            int st=arr[0][0];
            int en=arr[0][1];
            int i=0;
            vector<vector<int>> ans;
            while(i<arr.size())
            {
            while(i<arr.size() && arr[i][0]<=en) 
            {
            en=max(en,arr[i][1]);
            i++;
            }
            ans.push_back({st,en});
            if(i==arr.size()) break;
            st=arr[i][0];
            en=arr[i][1];
            }
            return ans;
            
    }
};
