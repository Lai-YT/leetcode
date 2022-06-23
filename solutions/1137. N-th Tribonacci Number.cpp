class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }
        int pre_pre_prev = 0;
        int pre_prev = 1;
        int prev = 1;
        int curr = 0;
        for (int i = 3; i <= n; ++i) {
            curr = pre_pre_prev + pre_prev + prev;
            pre_pre_prev = pre_prev;
            pre_prev = prev;
            prev = curr;
        }
        return curr;
    }
};
