class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, profit = 0;                 // left = 買入日
        for (int right = 1; right < prices.size(); right++) {   // right = 賣出日
            if (prices[right] < prices[left]) {
                left = right;                     // 找到更便宜的買點，視窗左邊直接跳過來
            } 
            else {
                profit = max(profit, prices[right] - prices[left]);
            };
        }
        return profit;     
    };
};
