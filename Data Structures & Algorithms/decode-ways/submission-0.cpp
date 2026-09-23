class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] - '0' > 0 ? 1 : 0;
        for(auto i = 2uz; i < dp.size(); i++){
            dp[i] += s[i - 1] - '0' > 0 ? dp[i - 1] : 0;
            int val = stoi(s.substr(i - 2, 2));
            dp[i] += val >= 10 && val <= 26 ? dp[i - 2] : 0;
        }
        return dp.back();
    }
};
