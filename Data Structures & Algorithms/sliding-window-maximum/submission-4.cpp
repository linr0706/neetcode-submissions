class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;          // 存「索引」，對應的數值由大到小
        vector<int> res;

        for (int i = 0; i < (int)nums.size(); i++) {
            // 1. 移除過期的：前端的索引已經滑出視窗
            if (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();

            // 2. 丟掉沒機會的：尾端比新數字小（或相等）的
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            // 3. 加入新的
            dq.push_back(i);

            // 4. 視窗滿了，前端就是最大值
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
