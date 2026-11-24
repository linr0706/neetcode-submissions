class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n, 0);
        st.push(0);
        for(int i = 1; i < n; i++){
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {// 今天比頂端那天熱
                int j = st.top();
                st.pop();
                res[j] = i - j;              // 第 j 天等了幾天
            }
            st.push(i);
        }
        return res;
    }
};
