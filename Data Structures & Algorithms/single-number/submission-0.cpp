class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int x=arr[0];
        for(int i=1;i<arr.size();i++) x^=arr[i];
        return x;
    }
};
