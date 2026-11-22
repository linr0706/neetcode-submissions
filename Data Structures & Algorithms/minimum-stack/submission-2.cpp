class MinStack {
private:
    stack<int> st;
    stack<int> minSt;   // 只存「歷次的最小值」

public:
    MinStack() {

    }

    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
    }

    void pop() {
        if (st.top() == minSt.top()) minSt.pop();   // 移除的剛好是最小值，minSt 才跟著 pop
        st.pop();
    }

    int top() { 
        return st.top(); 
    }

    int getMin() { 
        return minSt.top(); 
    }
};
