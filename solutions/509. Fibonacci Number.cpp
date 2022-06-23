class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int pre_prev = 0;
        int prev = 1;
        int curr = 0;
        for (int i = 2; i <= n; ++i) {
            curr = pre_prev + prev;
            pre_prev = prev;
            prev = curr;
        }
        return curr;
    }
};
