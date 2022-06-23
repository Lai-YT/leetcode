class Solution {
public:
    int minPartitions(string n) {
        char max = '0';
        for (char c : n) {
            if (c > max) {
                max = c;
                if (c == '9') {
                    return 9;
                }
            }
        }
        return max - 48;
    }
};
