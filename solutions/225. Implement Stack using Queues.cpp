class MyStack {
public:
    void push(int x) {
        queue_.push(x);
        /*
         * We perform the re-fill everytime,
         * so the elements are stored in reversed order.
         * If we do the re-fill only when `pop` is called,
         * `top` may need re-fill, too.
         */
        int size = queue_.size();
        while (size-- > 1) {
            queue_.push(queue_.front());
            queue_.pop();
        }
    }
​
    int pop() {
        int x = queue_.front();
        queue_.pop();
        return x;
    }
​
    int top() const {
        return queue_.front();
    }
​
    bool empty() const {
        return queue_.empty();
    }
​
private:
    std::queue<int> queue_{};
};
​
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
​
