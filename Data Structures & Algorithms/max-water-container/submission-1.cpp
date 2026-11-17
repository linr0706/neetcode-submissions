class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int res = 0;
        while (left < right) {
            int h = min(heights[left], heights[right]);
            res = max(res, h * (right - left));
            // 跳過所有不高於 h 的柱子，它們寬度更小、高度也沒更高
            while (left < right && heights[left] <= h) left++;
            while (left < right && heights[right] <= h) right--;
        }
        return res;
    }
};
