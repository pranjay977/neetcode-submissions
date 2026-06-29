class TimeMap {
public:
        map<string,vector<pair<int,string>>> mp;  
        TimeMap() {
        }
        
        void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        }
        
        string get(string key, int timestamp) {
            if(mp.find(key)==mp.end()) return "";
            vector<pair<int,string>> &res=mp[key];
auto index = upper_bound(
    res.begin(), res.end(), timestamp,
    [](int a, const pair<int,string>& b) {
        return a < b.first;
    }
);

if(index == res.begin()) return "";
index--;

return index->second;
}
};
