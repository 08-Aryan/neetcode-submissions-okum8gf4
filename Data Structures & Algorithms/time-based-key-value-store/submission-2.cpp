class TimeMap {
    unordered_map<string,vector<pair<int,string>>> TimeStore;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        TimeStore[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        int l = 0 , r = TimeStore[key].size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(timestamp >= TimeStore[key][mid].first){
                ans = TimeStore[key][mid].second;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};
