class MinStack {
private: // 成員變數，每個函式都能用，而且會一直存在
    stack<int> st;      
    stack<int> minSt;   // 存「到這層為止的最小值」，跟 st 一樣高

public:
    int minval = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        minval = min(minval, val);
        if (minSt.empty()) minSt.push(val);
        else minSt.push(min(val, minSt.top()));
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
