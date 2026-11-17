class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // 步驟 1：從右往左，算出每一格「右邊（含自己）最高」
        vector<int> maxRight(n);
        maxRight[n - 1] = height[n-1];
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i+1], height[i]);
        }

        // 步驟 2：從左往右走，peak 就是「左邊（含自己）最高」
        int peak = 0;
        int area = 0;
        for (int i = 0; i < n; i++) {
            peak = max(peak, height[i]); // 更新左邊最高
            area += min(peak, maxRight[i]) - height[i];           // 這一格的水
        }

        return area;
    }
};
