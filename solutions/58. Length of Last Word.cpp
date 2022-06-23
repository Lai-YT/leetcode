class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        auto itr = s.rbegin();
        while (itr != s.rend() && *itr == ' ')
            itr++;
        while (itr != s.rend() && *itr++ != ' ')
            count++;
        return count;
    }
};
