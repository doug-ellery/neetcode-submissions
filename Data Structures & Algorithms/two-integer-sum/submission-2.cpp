class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> my_map;
        for(int i = 0; i < nums.size(); i++){
            if(my_map.count(target - nums[i])){
                return {my_map[target - nums[i]], i};
            }
            else{
                my_map.insert({nums[i], i});
            }
        }
    }    
};
