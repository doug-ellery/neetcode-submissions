class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int bits = nums.size();
        vector<vector<int>> all_subs;
        for(int i = 0; i < (1<<nums.size()); i++){
            vector<int> subset;
            for(int j = 0; j < bits; j++){
                if(i & 1<<j){
                    subset.push_back(nums[j]);
                }
            }
            all_subs.push_back(subset);
        }
        return all_subs;
    }
};
