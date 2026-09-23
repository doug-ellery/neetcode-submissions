class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){return nums[0];}
        int temp = nums.back();
        nums.pop_back();
        vector<int> dp1(nums.size() + 1, 0);
        dp1[1] = nums[0];
        for(auto i = 2uz; i < dp1.size(); i++){
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
        }
        nums.push_back(temp);
        vector<int> dp2(nums.size(), 0);
        dp2[1] = nums[1];
        for(auto i = 2uz; i < dp2.size(); i++){
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }
        return max(dp1.back(), dp2.back());
    }
};
