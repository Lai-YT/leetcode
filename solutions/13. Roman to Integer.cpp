class Solution {
public:
    int romanToInt(char const & c) const {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        char last = ' ';
        int result = 0;
        for (char const & c : s) {
            if (romanToInt(last) < romanToInt(c))
                result -= romanToInt(last) * 2;
            result += romanToInt(c);
            last = c;
        }
        return result;
    }
};
