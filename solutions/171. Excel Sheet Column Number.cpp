class Solution {
public:
    int titleToNumber(string columnTitle) const {
        std::reverse(columnTitle.begin(), columnTitle.end());
    
        int result = 0;
        long base = 1;  /* the last unused multiply on NUM_OF_ALPHABET_ exceeds 2^31-1 */
        for (const char digit : columnTitle) {
            result += toInt_(digit) * base;
            base *= NUM_OF_ALPHABET_;
        }
        return result;
    }
private:
    static constexpr int NUM_OF_ALPHABET_ = 26;
​
    static int toInt_(const char digit) {
        return digit - 'A' + 1;
    }
};
​
