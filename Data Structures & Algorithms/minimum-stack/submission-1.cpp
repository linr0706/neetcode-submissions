class MinStack {
private:
    stack<pair<int,int>> st;   // (值, 到這層為止的最小值)

public:
    MinStack() {}

    void push(int val) {
        int curMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, curMin});
    }

    void pop() { 
        st.pop();
    }

    int top() {
        return st.top().first; 
    }

    int getMin() { 
        return st.top().second;
    }
};
