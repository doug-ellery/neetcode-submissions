class MinStack {
private:
    vector<int> my_stack;
    vector<int> mins;
public:
    MinStack() {
        my_stack = {};
        mins = {};
    }
    
    void push(int val) {
        my_stack.push_back(val);
        mins.push_back(mins.empty() || val < mins.back() ? val : mins.back());
    }
    
    void pop() {
        my_stack.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return my_stack.back();
    }
    
    int getMin() {
        return mins.back();
    }
};
