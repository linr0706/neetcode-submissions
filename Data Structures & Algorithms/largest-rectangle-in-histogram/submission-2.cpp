class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int best = 0;
        stack<int> st;                              // 存索引，高度由底到頂不會變矮

        for (int i = 0; i <= n; i++) {              // 注意是 <=，多跑一輪
            int h = (i == n) ? 0 : heights[i];      // 最後假裝有一根高度 0 的柱子

            while (!st.empty() && h < heights[st.top()]) {   // h 比頂端那根矮
                int height = heights[st.top()];
                st.pop();
                int L = st.empty() ? -1 : st.top();     // 左邊第一個更矮的
                int R = i;                             // 右邊第一個更矮的
                best = max(best, height * (R-L-1));   // 面積
            }
            st.push(i);
        };
        return best;
    }
};
