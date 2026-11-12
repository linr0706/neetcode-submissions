class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<pair<int, int>> items;

        // Step 1：統計頻率
        for(size_t i=0;i<nums.size();i++){
            freq[nums[i]]++;
        };
        // Step 2：將 Hash Map 轉成 Pair
        for(const auto&entry : freq){
            items.push_back({entry.first, entry.second});
        };
        // Step 3：依照頻率由大到小排序
        sort(items.begin(), items.end(),
            [](const pair<int,int>& a, const pair<int,int>& b) {
                return a.second > b.second ;// TODO：比較 a 和 b 的頻率
            }
        );
        // Step 4：建立答案容器
        vector<int> result;

        // Step 5：取出前 k 個原始數字
        for (int i = 0; i<k; i++) {
            result.push_back(items[i].first);
        };

        return result;        
    };
};
