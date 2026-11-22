class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;                              // ① 用 vector 當 stack
        st.reserve(tokens.size());

        for (const string& t : tokens) {
            if (t.size() == 1 && !isdigit(t[0])) {   // ② 判斷運算子
                int a = st.back(); st.pop_back();    // ③ 只寫一次：右邊的數字
                int& b = st.back();                  // ④ 左邊的數字，直接在原地修改
                switch (t[0]) {                      // ⑤ 用 switch 選運算
                    case '+': b += a; break;
                    case '-': b -= a; break;
                    case '*': b *= a; break;
                    case '/': b /= a; break;
                }
            } else {
                st.push_back(stoi(t));
            }
        }
        return st.back();
    }
};
