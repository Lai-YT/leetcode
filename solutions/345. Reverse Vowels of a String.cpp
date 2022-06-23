class Solution {
public:
    bool isVowel(char const & c) const {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || \
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        
        for (int i = 0, j = s.length() - 1; i < j;) {
            if (!isVowel(s.at(i))) i++;
            if (!isVowel(s.at(j))) j--;
            if (isVowel(s.at(i)) && isVowel(s.at(j))) swap(s.at(i++), s.at(j--));
        }
        return s;
    }
};
