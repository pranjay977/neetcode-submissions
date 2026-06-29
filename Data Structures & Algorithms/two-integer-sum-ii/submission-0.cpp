class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
     int e=0;
     int j=arr.size()-1;
     vector<int> ans;   
     while(e<j)
    {
    if((arr[e]+arr[j])==target)
    {
    ans.push_back(e+1);
    ans.push_back(j+1);
    return ans;
    }
    if((arr[e]+arr[j])<target) e++;
    else j--;
    }
    return ans;
    }
};
