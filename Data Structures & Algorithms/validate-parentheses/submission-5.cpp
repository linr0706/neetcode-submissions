class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;           // ① 奇數長度不可能合法

        string st;                                      // ② 用 string 當 stack
        for (char c : s) {
            if (c == '(') st.push_back(')');            // ③ 直接存「期待的右括號」
            else if (c == '[') st.push_back(']');
            else if (c == '{') st.push_back('}');
            else {
                if (st.empty() || st.back() != c) return false;
                st.pop_back();
            }
            if (st.size() > s.size() / 2) return false; // ④ 左括號太多，後面關不完
        }
        return st.empty();
    }
};
