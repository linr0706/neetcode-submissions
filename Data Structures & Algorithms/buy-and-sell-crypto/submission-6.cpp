class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];
        for(size_t i = 0; i < prices.size(); i++){
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i] - buy);
        }
        return profit;
    }
};
