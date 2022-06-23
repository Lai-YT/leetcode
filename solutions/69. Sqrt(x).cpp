class Solution {
public:
    int mySqrt(int x) {
        for (long i = 2; i < x; i++) {
            if (i * i > x) {
                return i - 1;
            }
        }
        return x == 0 ? 0 : 1;
    }
};
