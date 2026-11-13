class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<vector<int>> buckets(nums.size() + 1); //Vector 索引從 0 開始，若要能存取 buckets[8]，就必須配置 9 個位置(0~8)
        vector<int> result;
        for(size_t i = 0;i < nums.size();i++){
            freq[nums[i]]++;
        };

        for (const auto& entry : freq) {
            // entry.first  = 原始數字
            // entry.second = 出現次數
            buckets[entry.second].push_back(entry.first); // 把原始數字放進對應頻率的 Bucket
        }

        for (int f = static_cast<int>(nums.size()); f >= 1; f--) {
            for (int num : buckets[f]) {
                // 將目前的原始數字 num 加入 result
                result.push_back(num);

                // 若 result 已經收集到 k 個數字，就直接回傳 result
                if(result.size() == static_cast<size_t>(k)){
                    return result;
                };
            };
        };
        return result;
    };
};
