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
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> min_heap;
        for(auto& [value, freq] : set){
            min_heap.push({freq, value});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        
        vector<int> out;
        for(int i = 0; i < k; i++){
            out.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return out;
    }
};
