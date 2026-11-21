class Solution { //MaxHeap
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;    // (數值, 索引)，頂端是數值最大的
        vector<int> res;

        for (int i = 0; i < (int)nums.size(); i++) {
            // 1. 加入新數字
            pq.push({nums[i], i});

            // 2. 視窗還沒滿，先不記錄答案
            if (i < k - 1) continue;

            // 3. 頂端已經滑出視窗了，丟掉
            while (pq.top().second < i - k + 1) pq.pop();

            // 4. 現在頂端就是視窗最大值
            res.push_back(pq.top().first);
        }
        return res;
        
    }
};
