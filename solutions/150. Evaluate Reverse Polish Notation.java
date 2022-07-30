import java.util.Stack;
​
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (final String token : tokens) {
            if (this.isOperator(token)) {
                /* be careful of the order of operands */
                int b = stack.pop();
                int a = stack.pop();
​
                /* we're confident this conversion is safe after the `isOperator` check */
                char op = token.charAt(0);
​
                stack.push(this.operate(a, b, op));
            } else {
                stack.push(Integer.parseInt(token));
            }
        }
        return stack.peek();
    }
​
    private boolean isOperator(final String s) {
        return "+-*/".contains(s);  /* since won't be like "+-" here */
    }
​
    private int operate(final int a, final int b, final char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default:
                break;
        }
        /* we'll ignore the check on this since we're confident such
            exception won't occur */
        return 0;
    }
}
​
