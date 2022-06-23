class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack():size(0),now_loc("odd") {}
    
    /** Push element x onto stack. */
    void push(int x) {
        if (now_loc == "even") {
            even.push(x);
            while (!odd.empty()) {
                even.push(odd.front());
                odd.pop();
            } now_loc = "odd";
        } else {
            odd.push(x);
            while (!even.empty()) {
                odd.push(even.front());
                even.pop();
            } now_loc = "even";
        } size++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = 0;
        if (now_loc == "even") {
            n = odd.front();
            odd.pop();
        } else {
            n = even.front();
            even.pop();
        } size--;
        return n;
    }
    
    /** Get the top element. */
    int top() {
        if (now_loc == "even") return odd.front();
        else return even.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
private:
    queue<int> odd, even;
    int size;
    string now_loc;
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
