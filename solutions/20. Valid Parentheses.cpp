class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1) return false;
        stack<char> paren;
        paren.push('0');
        for (char c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                paren.push(c);
                break;
                case ')':
                    if (paren.top() != '(') return false;
                    paren.pop();
                    break;
                case ']':
                    if (paren.top() != '[') return false;
                    paren.pop();
                    break;
                case '}':
                    if (paren.top() != '{') return false;
                    paren.pop();
                    break; 
            }
        }
        return paren.top() == '0';
    }
};
