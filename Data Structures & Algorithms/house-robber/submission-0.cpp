class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for(auto i = 2uz; i < dp.size(); i++){
            dp[i] = nums[i - 1] + dp[i - 2];
            for(auto j = 0uz; j < i - 2; j++){
                dp[i] = max(dp[i], nums[i - 1] + dp[j]);
            }
            dp[i] = max(dp[i], dp[i - 1]);
        }
        return dp.back();
    }
};
