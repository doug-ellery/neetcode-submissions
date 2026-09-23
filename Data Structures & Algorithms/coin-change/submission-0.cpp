class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        unordered_set<int> coin_set;
        for(const int& coin : coins){
            coin_set.insert(coin);
        }
        dp[0] = 0;
        for(auto i = 1uz; i < dp.size(); i++){
            for(const int& coin : coins){
                if(coin <= i && dp[i - coin] != -1){
                    dp[i] = dp[i] == -1 ? dp[i - coin] + 1 : min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount];
    }
};
