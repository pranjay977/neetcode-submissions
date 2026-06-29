class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int st=arr[0][0];
        int en=arr[0][1];
        int i=0;
        while(i<arr.size())
        {
        int k=i;
        while(i<arr.size() && arr[i][0]<=en)
        {
            en=max(en,arr[i][1]);
            i++;
        }
        vector<int> res;
        res.push_back(st);
        res.push_back(en);
        ans.push_back(res);
        if(i==k) i++;
        if(i>=arr.size()) break;
        st=arr[i][0];
        en=arr[i][1];
        }
        return ans;
        }
        
    };
