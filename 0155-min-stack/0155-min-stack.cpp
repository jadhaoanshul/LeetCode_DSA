class MinStack {
    stack<long long> st;
    long long min;
public:
    MinStack() {
    }
    
    void push(int val) {
        long long v = val;
        if(st.empty()){
            min = v;
            st.push(v);
        }
        else{
            if(v>min){
                st.push(v);
            }
            else{
                st.push(2LL * v - min);
                min = v;
            }
        }
    }
    void pop() {
        if(st.empty())
            return;
        long long x = st.top();
        st.pop();
        if(x<min)
            min = 2*min - x;
    }
    
    int top() {
        if(st.empty())
            return -1;
        long long x = st.top();
        if(min<x)
            return x;
        return min;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */