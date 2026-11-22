class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                // 1. 先決定要找哪個左括號
                char need;
                if (c == ')') need = '(';
                else if (c == ']') need = '[';
                else need = '{';

                // 2. 再檢查 stack 頂端是不是它
                if (st.empty() || st.top() != need) return false;

                // 3. 配對成功，移除
                st.pop();
            }
        }
        return st.empty(); // 確保後面沒有左括號
    }
};
