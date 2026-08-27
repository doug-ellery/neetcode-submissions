class Solution {
public:
    void helper(int next_valid_idx, int curr_sum, const int target, vector<int> combo, vector<vector<int>>& all_combos, const vector<int>& nums){
        if(curr_sum == target){
            all_combos.push_back(combo);
            return;
        }
        else if(curr_sum < target){
            unordered_set<int> seen;
            for(int i = next_valid_idx; i < nums.size(); i++){
                if(seen.contains(nums[i])){continue;}
                vector<int> next_combo = combo;
                int next_sum = curr_sum;
                next_sum += nums[i];
                next_combo.push_back(nums[i]);
                helper(i + 1, next_sum, target, next_combo, all_combos, nums);
                seen.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combos;
        helper(0, 0, target, {}, combos, candidates);
        return combos;
    }
};
