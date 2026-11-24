class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int best = 0;
        vector<int> st;                 // ① 用 vector 當 stack
        st.reserve(n + 2);
        st.push_back(-1);               // ② 底部先放 -1

        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (st.size() > 1 && h <= heights[st.back()]) {   // ③ <=
                int height = heights[st.back()];
                st.pop_back();
                best = max(best, height * (i - st.back() - 1));
            }
            st.push_back(i);
        }
        return best;
    }
};