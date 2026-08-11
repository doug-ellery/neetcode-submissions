class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> my_map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        my_map[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = my_map[key].size() - 1;
        int max_t = -1;
        
        while(l <= r){
            int m = (l + r) / 2;
            if(my_map[key][m].second > timestamp){
                r = m - 1;
            }
            else if(my_map[key][m].second < timestamp){
                max_t = max(m, max_t);
                l = m + 1;
            }
            else{
                max_t = m;
                break;
            }
        }
        return max_t >= 0 ? my_map[key][max_t].first : "";
    }
};
