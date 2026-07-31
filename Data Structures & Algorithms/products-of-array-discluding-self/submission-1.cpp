class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_prods;
        vector<int> right_prods;
        for(int i = 0; i < nums.size(); i++){
            left_prods.push_back(i == 0 ? nums[i] : left_prods[left_prods.size() - 1] * nums[i]);
            right_prods.push_back(i == 0 ? nums[nums.size() - 1] : right_prods[right_prods.size() - 1] * nums[nums.size() - 1 - i]);
        }
        vector<int> out(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int l = i - 1;
            int r = right_prods.size() - i - 2;
            int prod = 1;
            prod *= l >= 0 ? left_prods[l] : 1;
            prod *= r >= 0 ? right_prods[r] : 1;
            out[i] = prod;
        }
        return out;
    }
};
