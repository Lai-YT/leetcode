class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) {
            return false;
        }
        auto parentheses = std::stack<char>{};
        for (char parenthsis : s) {
            if (isRightParenthsis_(parenthsis)) {
                if (parentheses.empty()
                        || parentheses.top() != getLeftParenthsisOf_(parenthsis)) {
                    return false;
                }
                parentheses.pop();
            } else {
                parentheses.push(parenthsis);
            }
        }
        return parentheses.empty();
    }
​
    static bool isRightParenthsis_(const char parenthsis) {
        return parenthsis == ')' || parenthsis == ']' || parenthsis == '}';
    }
​
    static char getLeftParenthsisOf_(const char rightParenthsis) {
        switch (rightParenthsis) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
            default:
                /* we'll ignore the check on this since we're confident such
                    exception won't occur */
                return '-';
        }
    }
};
​
