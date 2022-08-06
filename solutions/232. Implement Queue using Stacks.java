class MyQueue {
    /**
     * Always push to the pushStack and pop from the popStack.
     * If popStack is empty when being popped, elements are moved
     * from pushStack to popStack, FIFO is then achieved.
     * popStack only becomes empty every n pops and with time
     * complexity O(n) in that specific pop, so it's O(1) amortized.
     */
​
    private final int ALL_THE_CALLS_TO_POP_AND_PEEK_ARE_SAID_TO_BE_VALID = -1;
    /* no variable other than 2 stacks are used */
    private Stack<Integer> pushStack = new Stack<>();
    private Stack<Integer> popStack = new Stack<>();
​
    public void push(int x) {
        this.pushStack.push(x);
    }
​
    public int pop() {
        if (this.empty()) {
            return this.ALL_THE_CALLS_TO_POP_AND_PEEK_ARE_SAID_TO_BE_VALID;
        }
        if (this.popStack.isEmpty()) {
            this.fillPopStack();
        }
        return this.popStack.pop();
    }
​
    public int peek() {
        /* One may store the front element with and extra pointer so that peeking is always O(1)
         * but I'm not using any extra variables.
         */
        if (this.empty()) {
            return this.ALL_THE_CALLS_TO_POP_AND_PEEK_ARE_SAID_TO_BE_VALID;
        }
        if (this.popStack.isEmpty()) {
            this.fillPopStack();
        }
        return this.popStack.peek();
    }
​
    public boolean empty() {
        return this.pushStack.isEmpty() && this.popStack.isEmpty();
    }
​
    private void fillPopStack() {
        while (!this.pushStack.isEmpty()) {
            this.popStack.push(this.pushStack.pop());
        }
    }
}
​
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
