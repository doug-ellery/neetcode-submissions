class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = l + 1;
        int max_prof = 0;
        while(l < prices.size() - 1 && r < prices.size()){
            if(prices[r] > prices[l]){
                int prof = prices[r] - prices[l];
                max_prof = prof > max_prof ? prof : max_prof;
                r++;
            }
            else{
                l = r;
                r = l + 1;
            }

        }
        return max_prof;
    }
};
