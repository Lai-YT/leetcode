class MinStack {
public:
    /*
     * Within a stack, if A is under B, then A can't be touched without
     * touching B first.
     * So let every value node maintain a `min` value which tells the minimum
     * value under the specific node (itself included).
     */
    
    void push(int val) {
        stack_.push(
            MinStack::StackNode{
                val,
                stack_.empty() ? val: std::min(val, getMin())
            }
        );
    }
    
    void pop() {
        stack_.pop();
    }
    
    int top() {
        return stack_.top().val;
    }
    
    int getMin() {
        return stack_.top().min;
    }
​
    struct StackNode {
    public:
        const int val;
        const int min;
    };
    
private:
    std::stack<MinStack::StackNode> stack_{};
​
};
​
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
