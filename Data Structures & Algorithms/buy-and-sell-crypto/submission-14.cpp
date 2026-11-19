class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur = 0, best = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];   // 今天的漲跌
            cur = max(0, cur + diff);               // 接續 or 重新開始
            best = max(best, cur);                  // 記錄最佳
        }
        return best;
    }
};
