class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
            unordered_set<int> st;
            for(int e:nums)
            {
            if((st.insert(e)).second==false) return true;
            }
            return false;
    }
};