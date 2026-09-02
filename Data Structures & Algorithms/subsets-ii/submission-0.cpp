class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int bits = nums.size();
        vector<vector<int>> all_subs;
        for(int i = 0; i < (1<<bits); i++){
            vector<int> possible_subset;
            bool valid = true;
            for(int j = 0; j < bits; j++){
                if(i & 1<<j){
                    if(j > 0 && nums[j - 1] == nums[j] && !(i & 1<<(j - 1))){
                        valid = false;
                        break;
                    }
                    possible_subset.push_back(nums[j]);
                }
            }
            if(valid){all_subs.push_back(possible_subset);}
        }
        return all_subs;
    }
};
