class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int32_t left_prod = 1;
        int32_t right_prod = 1;
        int32_t best = INT_MIN;
        for(size_t i = 0; i < nums.size(); i++){
            left_prod = (left_prod == 0 ? 1 : left_prod) * nums[i];
            right_prod = (right_prod == 0 ? 1 : right_prod) * nums[nums.size() - 1 - i];
            best = max({left_prod, right_prod, best});
        }
        return best;
    }
};
