class Solution {
public:
    
    bool isPalindrome(string s) {
        char *head = &s[0], *tail = &s[s.length() - 1];
        while (head < tail) {
            if (!isalnum(*head)) {
                head++;
                continue;
            }
            if (!isalnum(*tail)) {
                tail--;
                continue;
            }
            if (*head != *tail && tolower(*head) != tolower(*tail)) 
                return false;
            head++, tail--;
        }
        return true;
    }
};
