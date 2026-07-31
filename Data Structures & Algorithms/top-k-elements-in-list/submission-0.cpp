class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> set;
        for(int i = 0; i < nums.size(); i++){
            if(set.count(nums[i])){
                set[nums[i]]++;
            }
            else{
                set.insert({nums[i], 1});
            }
        }
        vector<pair<int,int>> val_freq;
        for(auto& [value, freq] : set){
            val_freq.push_back({value, freq});
        }
        struct{
            bool operator()(pair<int, int> a, pair<int, int> b){
                return b.second < a.second;
            }
        }customLess;
        std::sort(val_freq.begin(), val_freq.end(), customLess);
        vector<int> out;
        for(int i = 0; i < k; i++){
            out.push_back(val_freq[i].first);
        }
        return out;
    }
};
