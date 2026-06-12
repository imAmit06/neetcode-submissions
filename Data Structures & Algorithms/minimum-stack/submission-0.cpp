class MinStack {
   public:
    stack<int> st;
    stack<int> min;

    MinStack() {}

    void push(int val) {
        st.push(val);

        if (min.empty()) {
            min.push(val);
        } else {
            min.top() > val ? min.push(val) : min.push(min.top());
        }
    }

    void pop() { st.pop(); min.pop(); }

    int top() { return st.top(); }

    int getMin() { return min.top(); }
};
