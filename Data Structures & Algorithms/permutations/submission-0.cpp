class Solution {
public:
    void helper(vector<vector<int>>& perms, unordered_set<int> curr_perm_set, vector<int> curr_perm, const vector<int>& nums){
        bool complete = true;
        for(const auto& num : nums){
            if(!curr_perm_set.contains(num)){
                unordered_set<int> next_perm_set = curr_perm_set;
                vector<int> next_perm = curr_perm;
                complete = false;
                next_perm_set.insert(num);
                next_perm.push_back(num);
                helper(perms, next_perm_set, next_perm, nums);
            }
        }
        if(complete){
            perms.push_back(curr_perm);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all_perms;
        helper(all_perms, {}, {}, nums);
        return all_perms;
    }
};
